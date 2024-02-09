import matplotlib.pyplot as plt
from scipy.spatial import ConvexHull

def read_points_from_file(filename):
    points = []
    with open(filename, 'r') as file:
        for line in file:
            x, y = map(int, line.split())
            points.append((x, y))
    return points

def plot_convex_hull(points):
    hull = ConvexHull(points)
    
    # Plot the convex hull as line segments
    for simplex in hull.simplices:
        plt.plot([points[i][0] for i in simplex] + [points[simplex[0]][0]],
                 [points[i][1] for i in simplex] + [points[simplex[0]][1]], 'k-')

    # Plot the original points
    x_values, y_values = zip(*points)
    plt.scatter(x_values, y_values, color='blue', marker='o')

    plt.title('Convex Hull of 2D Points')
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    filename = "hull.txt"  # Change this to the actual file name
    points = read_points_from_file(filename)
    plot_convex_hull(points)


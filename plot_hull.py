import matplotlib.pyplot as plt

def read_points_from_file(filename):
    points = []
    with open(filename, 'r') as file:
        for line in file:
            x, y = map(int, line.split())
            points.append((x, y))
    return points

def plot_points(points):
    x_values, y_values = zip(*points)
    plt.scatter(x_values, y_values, color='blue', marker='o')
    plt.title('2D Points')
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    filename = "hull.txt"  # Change this to the actual file name
    points = read_points_from_file(filename)
    plot_points(points)


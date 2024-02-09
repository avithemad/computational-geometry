import random
import matplotlib.pyplot as plt

def generate_2d_points(num_points):
    points = []
    for _ in range(num_points):
        x = random.randint(1, 100)  # You can adjust the range as needed
        y = random.randint(1, 100)
        points.append((x, y))
    return points

def write_points_to_file(filename, points):
    with open(filename, 'w') as file:
        file.write(f"{len(points)}\n")
        for point in points:
            file.write(f"{point[0]} {point[1]}\n")
            
def plot_points(points):
    x_values, y_values = zip(*points)
    plt.scatter(x_values, y_values, color='blue', marker='o')
    plt.title('2D Points')
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.grid(True)
    plt.show()


if __name__ == "__main__":
    num_points = 60  # Change this to the desired number of points
    points = generate_2d_points(num_points)
    write_points_to_file("output.txt", points)
    plot_points(points)


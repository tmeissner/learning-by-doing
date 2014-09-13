import math


# version with 2 separate functions

def distance(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

def perimeter(polygon):
    perimeter = 0
    points = polygon + [polygon[0]]
    for i in range(len(polygon)):
        perimeter += distance(points[i], points[i + 1])
    return perimeter


# oop version with classes

class Point:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance(self, p2):
        return math.sqrt((self.x - p2.x) ** 2 + (self.y - p2.y) ** 2)


class Polygon:

    def __init__(self, points = []):
        self.vertices = []
        for point in points:
            if isinstance(point, tuple):
                # *point splits point into 2 parameters for Point.__init__()
                point = Point(*point)
            self.vertices.append(point)

    def add_point(self, point):
        self.vertices.append((point))

    def perimeter(self):
        perimeter = 0
        try:
            points = self.vertices + [self.vertices[0]]
        except IndexError:
            print("The polygon has no points.")
        else:
            for i in range(len(self.vertices)):
                perimeter += points[i].distance(points[i + 1])
            return perimeter
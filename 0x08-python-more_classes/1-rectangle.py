#!/usr/bin/python3
"""define a Rectangle class."""



class Rectangle:
    """Represent a rectangle."""
    

    def __init__(self, width=0, height=0):
        """Initialize a new rectangle.

        args:
            width (int): The width of new rectangle.
            height (int): The heigth of new rectangle.
            """

            self.width = width
            self.height = height

    @property
    def width(self):
        """Get/set the width of the rectangle."""
        return self.__width

    @width.setter
    def width(self, value):
        if not isinstance(value, int):
            raise TypeError("width must be an integer")
        elif value < 0:
            raise ValueError("width must be >= 0")
        else:
            self.__width = value

    @property
    def height(self):
        """Get/set the height of rectangle."""
        return self.__height

    @height.setter
    def height(self, value):
        if not isinstance(value, int):
            raise TypeError("height must be an integer")
        elif value < 0:
            raise ValueError("height must be >= 0")
        else:
            self.__height = value

#!/usr/bin/python3
"""Define a Locked class."""



class LockedClass:
    """
    Prevent the user from initializing new LockedClass attributes
    for anything but attributes called 'first_name'.
    """

    __slots__ = ["first_name"]

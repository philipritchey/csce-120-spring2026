# Encapsulation

## Prompt

Write the function `void Point::rotate()` which rotates a 2-D `Point` 90 degrees anti-clockwise about the origin.

Assume the following definition for `Point` (you are not allowed to add any methods to `Point`):

```c++
class Point {
    int x;
    int y;

 public:
    Point(int x, int y) : x{x}, y{y} {}
    // TODO(student): Implement rotate
    void rotate();
};
```

## Approach

*Again, this problem is quite simple and yields to a concise solution but I want to illustrate a tactic which comes in handy on exam questions that disallow modification to the starter code.*

Suppose I know a function that takes an x-coordinate and a y-coordinate and rotates them anti-clockwise.

```c++
void rotate_xy(int& x, int&y) {
    int t = x;
    x = -y;
    y = t;
}
```

Of course, I could just copy the body of this function into `Point::rotate` and be done.  But imagine if rotating is just one step of many or has to be done many times.

Instead, I use `rotate_xy` within `Point::rotate`:

```c++
void Point::rotate() {
    rotate_xy(x, y);
}
```

The tactic here is that we can exfiltrate references to private attributes.  `Point::x` and `Point::y` are `private`. So, I cannot write, e.g.

```c++
Point p(1, 2);
rotate_xy(p.x, p.y);
```

But, since `Point::rotate` is a member of `Point`, it can access the private members.  So, `Point::rotate` can pass to `rotate_xy` references to  `Point::x` and `Point::y` and then `rotate_xy` **can** access them!

This is useful when the starter code doesn't provide an accessor (getter or setter) that you wish you had.

## Summary

* The starter code doesn't provide an accessor that you wish you had?
* No problem:
  * write a helper method that takes a reference to the attribute(s) you want to modify
  * invoke that function from within the class (the part you are allowed to modify/implement)

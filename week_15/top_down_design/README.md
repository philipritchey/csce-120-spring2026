# Top-Down Design

## Prompt

Write the function `int quadrant(Point p)` which takes a `Point` in 2-D space and returns the quadrant in which the point lies.

Assume the following definition for `Point`:

```c++
struct Point {
    int x;
    int y;
};
```

## Approach

*This is an easy problem and we could probably one-line it. But that is not the point.  We want to **think before we code**.*

### Decompose the problem

Break the problem into slightly smaller pieces that are slightly easier to solve.

There are 4 quadrants, all we have to do is figure out which one the point is in.

* If the point is in quadrant 1, the answer is 1.
* If the point is in quadrant 2, the answer is 2.
* If the point is in quadrant 3, thw answer is 3.
* Else, the answer is 4.

```c++
int quadrant(Point p) {
    if (in_q1(p)) return 1;
    if (in_q2(p)) return 2;
    if (in_q3(p)) return 3;
    return 4;
}
```

### Decompose the smaller problems

Now we have 3 smaller problems, which we can solve independently.

For each, decompose it one level further.

* A point is in quadrant 1 if it has positive x and positive y coordinates.

```c++
bool in_q1(Point p) {
    return has_positive_x(p)
        && has_positive_y(p);
}
```

* A point is in quadrant 2 if it has negative x and positive y coordinates.

```c++
bool in_q2(Point p) {
    return has_negative_x(p)
        && has_positive_y(p);
}
```

* A point is in quadrant 3 if it has negative x and negative y coordinates.

```c++
bool in_q3(Point p) {
    return has_negative_x(p)
        && has_negative_y(p);
}
```

### Continue decomposing until you reach problems which can be solved directly

Now we have 4 even smaller problems, each of which we can solve independently.  Moreover, these problems are now simple enough to be solved directly (i.e. no further decomposition is possible or necessary).

```c++
bool has_positive_x(Point p) {
    return p.x > 0;
}

bool has_positive_y(Point p) {
    return p.y > 0;
}

bool has_negative_x(Point p) {
    return p.x < 0;
}

bool has_negative_y(Point p) {
    return p.y < 0;
}
```

Even though these functions are overly-simple, imagine if they were not.  Imagine if, even after several rounds of decomposition, the problems still required several lines of code.  That these methods are so simple is because the problem is so simple.  A more complicated problem would require more rounds of decomposition and/or more complex methods.  **The point of decomposition is to reduce the complexity and lock it away with abstraction (e.g. functions).**

## Comparison without Decomposition/Abstraction

Here is one (fairly-straightforward) way to solve this problem without the (apparent) use of decomposition or abstraction.

```c++
int quadrant(Point p) {
    int Q[2][2] = {
        {3, 2},
        {4, 1}
    };
    return Q[p.x > 0][p.y > 0];
}
```

Quick! Is the code correct?  How do you know?  What are you doing/thinking to determine if the code is correct?

I want you to imagine the complexity (and pain) if the problem were not so easy.  If the problem required **much** more complicated cases.  The complexity would quickly swamp your ability to understand what was going on in the code, leading to increased probability of errors and increased difficulty in debugging (i.e. finding and fixing errors).

## Summary

* Decompose a problem into smaller, simpler problems
* Assume helper methods that solve the smaller problems
* Repeat (decompose -> helpers) until problem is as simple as can be
* Shorter code is not always better than longer code.
* Simpler code is almost always better than complex code.

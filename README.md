some requirements for the parade route :

It must start and end at building $1$, where her office is located.
It must visit each building the same number of times. Being in building $1$ at the start of the route does not count as a visit.
It must use each slide at least once.
It must have at most $10^6$ steps.
Given the layout of buildings and slides, help Melek find a route that satisfies all of the CEO's requirements, if one exists.

Input
The first line of the input gives the number of test cases, $\mathbf{T}$. $\mathbf{T}$ test cases follow. Each test case starts with a line containing two integers $\mathbf{B}$ and $\mathbf{S}$: the number of buildings and slides, respectively. Then, $\mathbf{S}$ lines follow. The $i$-th of these lines contains two integers $\mathbf{U_i}$ and $\mathbf{V_i}$, indicating that the $i$-th slide goes from building $\mathbf{U_i}$ to building $\mathbf{V_i}$.

Output
For each test case, output one line containing Case #x: y, where $x$ is the test case number (starting from 1). If there is no route that fulfills all the requirements, $y$ must be IMPOSSIBLE. If there is, $y$ must be an integer between $\mathbf{S}+1$ and $10^6+1$, inclusive, representing the length of one such route you want to exhibit. In that case, output another line containing $y$ integers $z_1\ z_2\ \dots\ z_y$, where $z_j$ is the $j$-th building in your proposed route. Notice that $z_1 = z_y = 1$ and that each building must appear the same number of times among the $z_j$, except for building $1$, which appears exactly one extra time.

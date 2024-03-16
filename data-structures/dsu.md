Disjoint set union with lazy update / union. Updates happen in two places:

1. Root of a component is updated during `unite`,
1. Childrens are updated while getting a `root`. This is the reason why we always access 

Initially, components are set to `-1`, which are counts of how many vertices are in each component. We need negative numbers to distinguish between parent vertices and counts. Whenever we merge, the root of a smaller component is set to the root of the larger component. If no negative values, we might need to use two different vectors.

Sources:

- https://usaco.guide/gold/dsu?lang=cpp
- https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/graphs%20(12)/DSU/DSU%20(7.6).h

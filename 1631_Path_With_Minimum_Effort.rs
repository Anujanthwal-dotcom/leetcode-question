// 1631. Path With Minimum Effort
// Difficulty: Medium
// URL: https://leetcode.com/problems/path-with-minimum-effort/
//
// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
//
// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
//
// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
//
//
//
// Example 1:
//
// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
//
// Example 2:
//
// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
//
// Example 3:
//
// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// Output: 0
// Explanation: This route does not require any effort.
//
//
//
// Constraints:
//
// 	  * rows == heights.length
//
// 	  * columns == heights[i].length
//
// 	  * 1 <= rows, columns <= 100
//
// 	  * 1 <= heights[i][j] <= 106

use std::collections::{BinaryHeap, VecDeque};
use std::cmp::Ordering;

#[derive(Eq, PartialEq, Debug)]
struct Node {
    effort: i32,
    row: usize,
    col: usize,
}

impl Ord for Node {
    fn cmp(&self, other: &Self)->Ordering {
        return other.effort.cmp(&self.effort);
    }
}

impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering>{
        return Some(self.cmp(other));
    }
}




impl Solution {
    pub fn minimum_effort_path(heights: Vec<Vec<i32>>) -> i32 {
        let rows = heights.len();
        let cols = heights[0].len();

        let mut dist = vec![vec![i32::MAX; cols]; rows];

        let mut heap = BinaryHeap::new();
        dist[0][0] = 0;

        heap.push(Node {effort: 0, row: 0, col: 0});

        let directions = [(0,1),(0,-1),(1,0),(-1,0)];

        while let Some(node) = heap.pop() {
            let Node {effort, row, col} = node;


            if row == rows -1 && col == cols -1 {
                return effort;
            }

            if effort > dist[row][col] {
                continue;
            }

            for (dr, dc) in directions {
                let nr = row as i32 + dr;
                let nc = col as i32 + dc;

                if nr >=0 && nr<rows as i32 && nc >= 0 && nc < cols as i32 {
                    let nr = nr as usize;
                    let nc = nc as usize;

                    let new_effort = effort.max((heights[row][col] as i32 - heights[nr][nc] as i32).abs());

                    if new_effort < dist[nr][nc] {
                        dist[nr][nc] = new_effort;
                        heap.push(Node {effort: new_effort, row: nr, col: nc});
                    }
                }
            }
        }

        return 0;
    }
}
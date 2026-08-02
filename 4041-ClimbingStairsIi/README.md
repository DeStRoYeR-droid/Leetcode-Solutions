# 3693. Climbing Stairs II

**Difficulty:** Medium  
[View on LeetCode](https://leetcode.com/problems/climbing-stairs-ii/)

---

You are climbing a staircase with `n + 1` steps, numbered from 0 to `n`.

You are also given a **1-indexed** integer array `costs` of length `n`, where `costs[i]` is the cost of step `i`.

From step `i`, you can jump **only** to step `i + 1`, `i + 2`, or `i + 3`. The cost of jumping from step `i` to step `j` is defined as: `costs[j] + (j - i)^2`

You start from step 0 with `cost = 0`.

Return the **minimum** total cost to reach step `n`.

**Example 1:**

**Input:** n = 4, costs = [1,2,3,4]

**Output:** 13

**Explanation:**

One optimal path is `0 &rarr; 1 &rarr; 2 &rarr; 4`

<table style="border: 1px solid black;">
	<tbody>
		<tr>
			<th style="border: 1px solid black;">Jump</th>
			<th style="border: 1px solid black;">Cost Calculation</th>
			<th style="border: 1px solid black;">Cost</th>
		</tr>
	</tbody>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">0 &rarr; 1</td>
			<td style="border: 1px solid black;"><code>costs[1] + (1 - 0)<sup>2</sup> = 1 + 1</code></td>
			<td style="border: 1px solid black;">2</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">1 &rarr; 2</td>
			<td style="border: 1px solid black;"><code>costs[2] + (2 - 1)<sup>2</sup> = 2 + 1</code></td>
			<td style="border: 1px solid black;">3</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2 &rarr; 4</td>
			<td style="border: 1px solid black;"><code>costs[4] + (4 - 2)<sup>2</sup> = 4 + 4</code></td>
			<td style="border: 1px solid black;">8</td>
		</tr>
	</tbody>
</table>

Thus, the minimum total cost is `2 + 3 + 8 = 13`

**Example 2:**

**Input:** n = 4, costs = [5,1,6,2]

**Output:** 11

**Explanation:**

One optimal path is `0 &rarr; 2 &rarr; 4`

<table style="border: 1px solid black;">
	<tbody>
		<tr>
			<th style="border: 1px solid black;">Jump</th>
			<th style="border: 1px solid black;">Cost Calculation</th>
			<th style="border: 1px solid black;">Cost</th>
		</tr>
	</tbody>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">0 &rarr; 2</td>
			<td style="border: 1px solid black;"><code>costs[2] + (2 - 0)<sup>2</sup> = 1 + 4</code></td>
			<td style="border: 1px solid black;">5</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2 &rarr; 4</td>
			<td style="border: 1px solid black;"><code>costs[4] + (4 - 2)<sup>2</sup> = 2 + 4</code></td>
			<td style="border: 1px solid black;">6</td>
		</tr>
	</tbody>
</table>

Thus, the minimum total cost is `5 + 6 = 11`

**Example 3:**

**Input:** n = 3, costs = [9,8,3]

**Output:** 12

**Explanation:**

The optimal path is `0 &rarr; 3` with total cost = `costs[3] + (3 - 0)^2 = 3 + 9 = 12`

**Constraints:**

- `1 <= n == costs.length <= 10^5​​​​​​​`
- `1 <= costs[i] <= 10^4`

# 3621. Number of Integers With Popcount-Depth Equal to K I

**Difficulty:** Hard  
[View on LeetCode](https://leetcode.com/problems/number-of-integers-with-popcount-depth-equal-to-k-i/)

---

You are given two integers `n` and `k`.

For any positive integer `x`, define the following sequence:

- `p_0 = x`
- `p_i+1 = popcount(p_i)` for all `i >= 0`, where `popcount(y)` is the number of set bits (1's) in the binary representation of `y`.

This sequence will eventually reach the value 1.

The **popcount-depth** of `x` is defined as the **smallest** integer `d >= 0` such that `p_d = 1`.

For example, if `x = 7` (binary representation `"111"`). Then, the sequence is: `7 &rarr; 3 &rarr; 2 &rarr; 1`, so the popcount-depth of 7 is 3.

Your task is to determine the number of integers in the range `[1, n]` whose popcount-depth is **exactly** equal to `k`.

Return the number of such integers.

**Example 1:**

**Input:** n = 4, k = 1

**Output:** 2

**Explanation:**

The following integers in the range `[1, 4]` have popcount-depth exactly equal to 1:

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th align="center" style="border: 1px solid black;">x</th>
			<th align="center" style="border: 1px solid black;">Binary</th>
			<th align="left" style="border: 1px solid black;">Sequence</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td align="center" style="border: 1px solid black;">2</td>
			<td align="center" style="border: 1px solid black;"><code>&quot;10&quot;</code></td>
			<td align="left" style="border: 1px solid black;"><code>2 &rarr; 1</code></td>
		</tr>
		<tr>
			<td align="center" style="border: 1px solid black;">4</td>
			<td align="center" style="border: 1px solid black;"><code>&quot;100&quot;</code></td>
			<td align="left" style="border: 1px solid black;"><code>4 &rarr; 1</code></td>
		</tr>
	</tbody>
</table>

Thus, the answer is 2.

**Example 2:**

**Input:** n = 7, k = 2

**Output:** 3

**Explanation:**

The following integers in the range `[1, 7]` have popcount-depth exactly equal to 2:

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">x</th>
			<th style="border: 1px solid black;">Binary</th>
			<th style="border: 1px solid black;">Sequence</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;"><code>&quot;11&quot;</code></td>
			<td style="border: 1px solid black;"><code>3 &rarr; 2 &rarr; 1</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">5</td>
			<td style="border: 1px solid black;"><code>&quot;101&quot;</code></td>
			<td style="border: 1px solid black;"><code>5 &rarr; 2 &rarr; 1</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">6</td>
			<td style="border: 1px solid black;"><code>&quot;110&quot;</code></td>
			<td style="border: 1px solid black;"><code>6 &rarr; 2 &rarr; 1</code></td>
		</tr>
	</tbody>
</table>

Thus, the answer is 3.

**Constraints:**

- `1 <= n <= 10^15`
- `0 <= k <= 5`

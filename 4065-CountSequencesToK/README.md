# 3850. Count Sequences to K

**Difficulty:** Hard  
[View on LeetCode](https://leetcode.com/problems/count-sequences-to-k/)

---

You are given an integer array `nums`, and an integer `k`.

Start with an initial value `val = 1` and process `nums` from left to right. At each index `i`, you must choose **exactly one** of the following actions:

- Multiply `val` by `nums[i]`.
- Divide `val` by `nums[i]`.
- Leave `val` unchanged.

After processing all elements, `val` is considered **equal** to `k` only if its final rational value **exactly** equals `k`.

Return the count of **distinct** sequences of choices that result in `val == k`.

**Note:** Division is rational (exact), not integer division. For example, `2 / 4 = 1 / 2`.

**Example 1:**

**Input:** nums = [2,3,2], k = 6

**Output:** 2

**Explanation:**

The following 2 distinct sequences of choices result in `val == k`:

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">Sequence</th>
			<th style="border: 1px solid black;">Operation on <code>nums[0]</code></th>
			<th style="border: 1px solid black;">Operation on <code>nums[1]</code></th>
			<th style="border: 1px solid black;">Operation on <code>nums[2]</code></th>
			<th style="border: 1px solid black;">Final <code>val</code></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">Multiply: <code>val = 1 * 2 = 2</code></td>
			<td style="border: 1px solid black;">Multiply: <code>val = 2 * 3 = 6</code></td>
			<td style="border: 1px solid black;">Leave <code>val</code> unchanged</td>
			<td style="border: 1px solid black;">6</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">Leave <code>val</code> unchanged</td>
			<td style="border: 1px solid black;">Multiply: <code>val = 1 * 3 = 3</code></td>
			<td style="border: 1px solid black;">Multiply: <code>val = 3 * 2 = 6</code></td>
			<td style="border: 1px solid black;">6</td>
		</tr>
	</tbody>
</table>

**Example 2:**

**Input:** nums = [4,6,3], k = 2

**Output:** 2

**Explanation:**

The following 2 distinct sequences of choices result in `val == k`:

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">Sequence</th>
			<th style="border: 1px solid black;">Operation on <code>nums[0]</code></th>
			<th style="border: 1px solid black;">Operation on <code>nums[1]</code></th>
			<th style="border: 1px solid black;">Operation on <code>nums[2]</code></th>
			<th style="border: 1px solid black;">Final <code>val</code></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">Multiply: <code>val = 1 * 4 = 4</code></td>
			<td style="border: 1px solid black;">Divide: <code>val = 4 / 6 = 2 / 3</code></td>
			<td style="border: 1px solid black;">Multiply: <code>val = (2 / 3) * 3 = 2</code></td>
			<td style="border: 1px solid black;">2</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">Leave <code>val</code> unchanged</td>
			<td style="border: 1px solid black;">Multiply: <code>val = 1 * 6 = 6</code></td>
			<td style="border: 1px solid black;">Divide: <code>val = 6 / 3 = 2</code></td>
			<td style="border: 1px solid black;">2</td>
		</tr>
	</tbody>
</table>

**Example 3:**

**Input:** nums = [1,5], k = 1

**Output:** 3

**Explanation:**

The following 3 distinct sequences of choices result in `val == k`:

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">Sequence</th>
			<th style="border: 1px solid black;">Operation on <code>nums[0]</code></th>
			<th style="border: 1px solid black;">Operation on <code>nums[1]</code></th>
			<th style="border: 1px solid black;">Final <code>val</code></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">Multiply: <code>val = 1 * 1 = 1</code></td>
			<td style="border: 1px solid black;">Leave <code>val</code> unchanged</td>
			<td style="border: 1px solid black;">1</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">Divide: <code>val = 1 / 1 = 1</code></td>
			<td style="border: 1px solid black;">Leave <code>val</code> unchanged</td>
			<td style="border: 1px solid black;">1</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">Leave <code>val</code> unchanged</td>
			<td style="border: 1px solid black;">Leave <code>val</code> unchanged</td>
			<td style="border: 1px solid black;">1</td>
		</tr>
	</tbody>
</table>

**Constraints:**

- `1 <= nums.length <= 19`
- `1 <= nums[i] <= 6`
- `1 <= k <= 10^15`

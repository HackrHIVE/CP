#include <bits/stdc++.h>
/*
<div class="ps-content-wrapper-v0">
<p>Given a string, reduce it in such a way that all of its substrings are distinct. To do so, you may delete any character of the string at any index. What is the minimum number of deletions needed in order to complete this task?</p>

<p>&nbsp;</p>

<p><em>Note: A substring is a contiguous sequence of characters within a string. It can be formed by deleting some (0 or more) characters from the left of the string and some (0 or more) characters from the right of the string.</em></p>

<p>&nbsp;</p>

<p>For example, let's say the given string is <em>s = "abab"</em>. Currently, the substrings are not distinct⁠—the substring "ab" is found starting at both index 0 and index 2. By deleting s[2] and s[3], the string becomes "ab", where all substrings are distinct. Therefore, the answer is 2 because this required 2 deletions. (Note that "aba" is not acceptable because the character 'a' counts as a substring. In "aba", there are two instances of the substring "a".)</p>
&nbsp;

<p class="section-title">Function Description</p>

<p>Complete the function <em>getMinDeletions</em> in the editor below.</p>

<p>&nbsp;</p>

<p>getMinDeletions has the following parameter(s):</p>

<p>&nbsp;&nbsp;&nbsp;&nbsp;string <em>s:</em>&nbsp; the given string</p>

<p>Returns:</p>

<p>&nbsp;&nbsp;&nbsp;&nbsp;int: the minimum number of deletions needed to make <em>s</em>&nbsp;have only distinct substrings in it</p>

<p>&nbsp;</p>

<p class="section-title">Constraints</p>

<ul>
	<li>
	<p>1 ≤&nbsp;<em>n</em>&nbsp;≤ 10<sup>5</sup></p>
	</li>
</ul>

<p>&nbsp;</p>
<!-- <StartOfInputFormat> DO NOT REMOVE THIS LINE-->

<details><summary class="section-title">Input Format For Custom Testing</summary>

<div class="collapsable-details">
<p>The first line contains a string, <em>s</em>.</p>
</div>
</details>
<!-- </StartOfInputFormat> DO NOT REMOVE THIS LINE-->

<details open="open"><summary class="section-title">Sample Case 0</summary>

<div class="collapsable-details">
<p class="section-title">Sample Input For Custom Testing</p>

<pre>STDIN &nbsp; &nbsp; Function
----- &nbsp; &nbsp; --------
abcab  =&gt; s = "abcab"</pre>

<p class="section-title">Sample Output</p>

<pre>2</pre>

<p class="section-title">Explanation</p>

<p>By deleting the first 2 characters, the string becomes "cab", which has only distinct substrings in it. Therefore, the answer is 2.</p>
</div>
</details>

<details><summary class="section-title">Sample Case 1</summary>

<div class="collapsable-details">
<p class="section-title">Sample Input For Custom Testing</p>

<pre>abcabc</pre>

<p class="section-title">Sample Output</p>

<pre>3</pre>

<p class="section-title">Explanation</p>

<p>By deleting the characters at indices 0, 4, and 5, the string becomes "bca", which has only distinct substrings in it. Because this required 3 deletions, the answer is 3.</p>
</div>
</details>
</div>
*/
using namespace std;
int getMinDeletions(string s) {
    int *arr = new int[26];
    memset(arr,0,sizeof(int)*26);
    int deletions = 0;
    for(int i=0;i<s.length();i++){
        arr[s[i]-97]++;
        if(arr[s[i]-97]>1) deletions++;
    }
    return deletions;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = getMinDeletions(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

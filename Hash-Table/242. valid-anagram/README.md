# 242. Valid Anagram

**LeetCode Problem:** [Valid
Anagram](https://leetcode.com/problems/valid-anagram/)\
**Difficulty:** Easy\
**Topics:** Hash Table, String, Sorting

------------------------------------------------------------------------

## Problem Statement

Given two strings `s` and `t`, return `true` if `t` is an anagram of
`s`, and `false` otherwise.

An **anagram** is a word or string formed by rearranging the characters
of another word or string, using each character the same number of
times.

### Example 1

**Input:** `s = "anagram", t = "nagaram"`

**Output:** `true`

**Explanation:** Both strings contain the same characters with the same
frequencies.

### Example 2

**Input:** `s = "rat", t = "car"`

**Output:** `false`

**Explanation:** The strings contain different characters.

------------------------------------------------------------------------

## Constraints

-   `1 <= s.length, t.length <= 5 * 10⁴`
-   `s` and `t` consist of lowercase English letters.

## Follow-up

What if the inputs contain Unicode characters? How would you adapt your
solution to such a case?

------------------------------------------------------------------------

Explored multiple approaches, from brute force to optimized solutions,
along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it
a try yourself!

------------------------------------------------------------------------

## Unicode Follow-up Helper

The Unicode follow-up versions below use this shared helper to decode
valid UTF-8 strings into Unicode code points. Each follow-up snippet
assumes this helper is available in the same file.

**Important:** This is a compact educational decoder for valid UTF-8
input. It does not validate malformed UTF-8. For production code, use a
well-tested Unicode library.

``` cpp
vector<char32_t> decodeUTF8(const string& s) {
    vector<char32_t> chars;

    for (size_t i = 0; i < s.size();) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        char32_t cp = 0;
        size_t len = 0;

        if (c <= 0x7F) {
            cp = c;
            len = 1;
        } else if ((c & 0xE0) == 0xC0) {
            cp = c & 0x1F;
            len = 2;
        } else if ((c & 0xF0) == 0xE0) {
            cp = c & 0x0F;
            len = 3;
        } else {
            cp = c & 0x07;
            len = 4;
        }

        for (size_t j = 1; j < len; j++) {
            cp = (cp << 6) |
                 (static_cast<unsigned char>(s[i + j]) & 0x3F);
        }

        chars.push_back(cp);
        i += len;
    }

    return chars;
}
```

The Unicode snippets compare code points. If visually equivalent text
with different code-point sequences should be treated as equal,
normalize both strings first using a Unicode library.

------------------------------------------------------------------------

## 1. Sorting --- Sort Both Strings and Compare

**Approach:** Sort both strings in ascending order using
`sort(s.begin(), s.end())` and `sort(t.begin(), t.end())`.

If the strings are anagrams, sorting places the same characters in the
same order in both strings.

Finally, compare the sorted strings using `s == t`. If they are equal,
return `true`; otherwise, return `false`.

``` cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        // Step 2: Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // Step 3: Compare the sorted strings
        return s == t;
    }
};
```

**Time Complexity:** `O(n log n + m log m)`

**Space Complexity:** `O(n + m)` for the by-value input strings; sorting
itself uses implementation-dependent stack space.

### Unicode Follow-up --- Sorting Unicode Code Points

Decode both UTF-8 strings into Unicode code points, sort those code
points, and compare the resulting sequences. This is the Unicode version
of the sorting approach.

``` cpp
bool isAnagramUnicodeSorting(const string& s, const string& t) {
    vector<char32_t> charsS = decodeUTF8(s);
    vector<char32_t> charsT = decodeUTF8(t);

    if (charsS.size() != charsT.size())
        return false;

    sort(charsS.begin(), charsS.end());
    sort(charsT.begin(), charsT.end());

    return charsS == charsT;
}
```

**Time Complexity:** `O(n log n + m log m)` in the number of decoded
code points.

**Space Complexity:** `O(n + m)` for the decoded sequences.

------------------------------------------------------------------------

## 2. Hashing --- Two Hash Maps for Character Frequency Counting

**Approach:** Create two `unordered_map` objects to store the frequency
of each character in strings `s` and `t`.

Traverse both strings and increment the frequency of each character.
Then compare the frequencies of all lowercase English letters from `'a'`
to `'z'`.

If any frequency differs, return `false`; otherwise, return `true`.

``` cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        // Step 1: Create two maps
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;

        // Step 2: Count characters in s
        for (int i = 0; i < s.length(); i++) {
            mapS[s[i]]++;
        }

        // Step 3: Count characters in t
        for (int i = 0; i < t.length(); i++) {
            mapT[t[i]]++;
        }

        // Step 4: Compare character frequencies
        for (char c = 'a'; c <= 'z'; c++) {
            if (mapS[c] != mapT[c]) {
                return false;
            }
        }

        // Step 5: All frequencies match
        return true;
    }
};
```

**Time Complexity:** `O(n + m)`

**Space Complexity:** `O(1)` under the problem's fixed lowercase-English
alphabet constraint.

### Unicode Follow-up --- Two Hash Maps of Code Points

Decode each string and count every Unicode code point in a separate map.
Compare the complete maps instead of checking only `'a'` through `'z'`.

``` cpp
bool isAnagramUnicodeTwoMaps(const string& s, const string& t) {
    vector<char32_t> charsS = decodeUTF8(s);
    vector<char32_t> charsT = decodeUTF8(t);

    if (charsS.size() != charsT.size())
        return false;

    unordered_map<char32_t, int> mapS;
    unordered_map<char32_t, int> mapT;

    for (char32_t c : charsS)
        mapS[c]++;

    for (char32_t c : charsT)
        mapT[c]++;

    return mapS == mapT;
}
```

**Time Complexity:** Expected `O(n + m)`.

**Space Complexity:** `O(n + m)` in the worst case for the decoded
sequences and maps.

------------------------------------------------------------------------

## 3. Hashing --- Single Hash Map with Frequency Increment and Decrement

**Approach:** Create a single `unordered_map` to store the frequency of
each character in string `s`.

Traverse `s` and increment each character's count. Then traverse `t` and
decrement the count of each character.

Finally, iterate through the map and check whether every frequency is
zero.

If any count is non-zero, return `false`; otherwise, return `true`.

``` cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        // Step 1: Create one map
        unordered_map<char, int> freq;

        // Step 2: Count characters in s
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        // Step 3: Decrease counts using t
        for (int i = 0; i < t.length(); i++) {
            freq[t[i]]--;
        }

        // Step 4: Check whether every count is zero
        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second != 0) {
                return false;
            }
        }

        // Step 5: All counts are zero
        return true;
    }
};
```

**Time Complexity:** `O(n + m)`

**Space Complexity:** `O(1)` under the problem's fixed lowercase-English
alphabet constraint.

### Unicode Follow-up --- Single Map with Code-Point Frequency Increment and Decrement

Keep the same frequency-balancing idea, but decode the UTF-8 strings
first and use `char32_t` keys.

``` cpp
bool isAnagramUnicodeSingleMap(const string& s, const string& t) {
    vector<char32_t> charsS = decodeUTF8(s);
    vector<char32_t> charsT = decodeUTF8(t);

    if (charsS.size() != charsT.size())
        return false;

    unordered_map<char32_t, int> freq;

    for (char32_t c : charsS)
        freq[c]++;

    for (char32_t c : charsT)
        freq[c]--;

    for (const auto& entry : freq) {
        if (entry.second != 0)
            return false;
    }

    return true;
}
```

**Time Complexity:** Expected `O(n + m)`.

**Space Complexity:** `O(n + m)` in the worst case for the decoded
sequences and map.

------------------------------------------------------------------------

## 4. Hashing --- Single Hash Map with Combined Frequency Counting

**Approach:** Create a single `unordered_map` to track character
frequencies. Use one loop with the `||` (logical OR) operator in the
condition `i < s.length() || i < t.length()` to continue iterating as
long as at least one string has remaining characters.

Increment the count for characters in `s` and decrement the count for
characters in `t`, using separate boundary checks to avoid accessing
characters beyond either string's length.

Finally, check whether every frequency is zero. If any count is
non-zero, return `false`; otherwise, return `true`.

``` cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        // Step 1: Create one map
        unordered_map<char, int> freq;

        // Step 2: Process both strings in one loop
        for (int i = 0; i < s.length() || i < t.length(); i++) {

            if (i < s.length()) {
                freq[s[i]]++;
            }

            if (i < t.length()) {
                freq[t[i]]--;
            }
        }

        // Step 3: Check whether every frequency is zero
        for (auto entry : freq) {
            if (entry.second != 0) {
                return false;
            }
        }

        // Step 4: All counts balance
        return true;
    }
};
```

**Time Complexity:** `O(n + m)`

**Space Complexity:** `O(1)` under the problem's fixed lowercase-English
alphabet constraint.

### Unicode Follow-up --- One Loop over Decoded Code Points

After decoding both strings, use the same combined-loop idea. The
boundary checks now apply to the decoded code-point vectors rather than
UTF-8 bytes.

``` cpp
bool isAnagramUnicodeOneLoop(const string& s, const string& t) {
    vector<char32_t> charsS = decodeUTF8(s);
    vector<char32_t> charsT = decodeUTF8(t);

    if (charsS.size() != charsT.size())
        return false;

    unordered_map<char32_t, int> freq;

    for (size_t i = 0; i < charsS.size() || i < charsT.size(); i++) {
        if (i < charsS.size())
            freq[charsS[i]]++;

        if (i < charsT.size())
            freq[charsT[i]]--;
    }

    for (const auto& entry : freq) {
        if (entry.second != 0)
            return false;
    }

    return true;
}
```

**Time Complexity:** Expected `O(n + m)`.

**Space Complexity:** `O(n + m)` in the worst case for the decoded
sequences and map.

------------------------------------------------------------------------

## 5. Frequency Array --- Single Array with Increment and Decrement

**Approach:** Create an integer array `freq[26]` initialized to `0`,
where each index represents a lowercase English letter from `'a'` to
`'z'`.

To find the correct index for a character, subtract `'a'` from it. For
example, `'a' - 'a' = 0`, `'b' - 'a' = 1`, and `'z' - 'a' = 25`.

### Character Frequency Mapping

Consider the string `s = "dad"`.

The expression `s[i] - 'a'` converts each character into its
corresponding array index. The frequency at that index is incremented
whenever the character appears.

**Code:**

``` cpp
int freq[26] = {0};
string s = "dad";

for (int i = 0; i < s.length(); i++) {
    freq[s[i] - 'a']++;
}
```

  -------------------------------------------------------------------------
  Character       Calculation              Array Index      Frequency After
                                                         Processing `"dad"`
  --------------- --------------- -------------------- --------------------
  `'a'`           `'a' - 'a'`                        0                    1

  `'b'`           `'b' - 'a'`                        1                    0

  `'c'`           `'c' - 'a'`                        2                    0

  `'d'`           `'d' - 'a'`                        3                    2

  `'e'`           `'e' - 'a'`                        4                    0

  `...`           `...`                          `...`                `...`

  `'z'`           `'z' - 'a'`                       25                    0
  -------------------------------------------------------------------------

This maps every lowercase letter to an index between `0` and `25`.
Traverse string `s` and increment the corresponding counter for each
character. Then traverse string `t` and decrement the corresponding
counter.

Finally, check all 26 counters. If any counter is non-zero, return
`false`; otherwise, return `true`.

``` cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        // Step 1: Create 26 counters, all initialized to 0
        int freq[26] = {0};

        // Step 2: Count each character in string s
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        // Step 3: Decrease the count for each character in string t
        for (int i = 0; i < t.length(); i++) {
            freq[t[i] - 'a']--;
        }

        // Step 4: Check whether every counter is 0
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        // Step 5: All character counts match
        return true;
    }
};
```

**Time Complexity:** `O(n + m)`

**Space Complexity:** `O(1)`

### Unicode Follow-up --- Dynamic Frequency Map Instead of a Fixed Array

A fixed array of size 26 cannot represent every Unicode code point. A
direct array indexed by every possible Unicode code point would be
wasteful. To preserve the single-counter idea, decode the strings and
use a map keyed by `char32_t`.

``` cpp
bool isAnagramUnicodeSingleFrequency(const string& s, const string& t) {
    vector<char32_t> charsS = decodeUTF8(s);
    vector<char32_t> charsT = decodeUTF8(t);

    if (charsS.size() != charsT.size())
        return false;

    unordered_map<char32_t, int> freq;

    for (char32_t c : charsS)
        freq[c]++;

    for (char32_t c : charsT)
        freq[c]--;

    for (const auto& entry : freq) {
        if (entry.second != 0)
            return false;
    }

    return true;
}
```

**Time Complexity:** Expected `O(n + m)`.

**Space Complexity:** `O(n + m)` in the worst case for the decoded
sequences and map.

------------------------------------------------------------------------

## 6. Frequency Array --- Two Arrays with Character Frequency Comparison

**Approach:** First, check whether the lengths of `s` and `t` are
different. If they are, return `false` because anagrams must contain the
same number of characters.

Create two integer arrays, `freqS[26]` and `freqT[26]`, initialized to
zero. Traverse each string and increment the corresponding counter using
`character - 'a'` to map each lowercase letter to an index from `0` to
`25`.

Finally, compare all 26 counters. If any frequency differs, return
`false`; otherwise, return `true`.

``` cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        // Step 1: Check if lengths are different
        if (s.length() != t.length()) {
            return false;
        }

        // Step 2: Create separate frequency arrays
        int freqS[26] = {0};
        int freqT[26] = {0};

        // Step 3: Count characters in s
        for (int i = 0; i < s.length(); i++) {
            freqS[s[i] - 'a']++;
        }

        // Step 4: Count characters in t
        for (int i = 0; i < t.length(); i++) {
            freqT[t[i] - 'a']++;
        }

        // Step 5: Compare all 26 counters
        for (int i = 0; i < 26; i++) {
            if (freqS[i] != freqT[i]) {
                return false;
            }
        }

        // Step 6: All frequencies match
        return true;
    }
};
```

**Time Complexity:** `O(n)`, because the lengths are checked first and
the remaining work processes equal-length strings.

**Space Complexity:** `O(1)`

### Unicode Follow-up --- Two Dynamic Frequency Maps

To adapt the two-array idea, use two maps keyed by Unicode code points.
Each map stores the frequency of the corresponding code point in one
string. Compare the complete maps at the end.

``` cpp
bool isAnagramUnicodeTwoFrequencies(const string& s, const string& t) {
    vector<char32_t> charsS = decodeUTF8(s);
    vector<char32_t> charsT = decodeUTF8(t);

    if (charsS.size() != charsT.size())
        return false;

    unordered_map<char32_t, int> freqS;
    unordered_map<char32_t, int> freqT;

    for (char32_t c : charsS)
        freqS[c]++;

    for (char32_t c : charsT)
        freqT[c]++;

    return freqS == freqT;
}
```

**Time Complexity:** Expected `O(n + m)`.

**Space Complexity:** `O(n + m)` in the worst case for the decoded
sequences and both maps.

------------------------------------------------------------------------

## 7. Frequency Array --- Single 256-Element Array with Simultaneous Counting

**Approach:** First, check whether the lengths of `s` and `t` are
different. If they are, return `false`.

Create a frequency array of size `256`, initialized to zero, to track
all possible byte values.

Use a single loop to increment the count for each byte in `s` and
decrement the count for the corresponding byte in `t`, using
`static_cast<unsigned char>` to ensure valid array indices.

In the anagram solution, `freq[static_cast<unsigned char>(s[i])]++`
increases the counter for a byte in `s`, while
`freq[static_cast<unsigned char>(t[i])]--` decreases the counter for a
byte in `t`. If all counters return to zero, the byte frequencies match.

### Understanding `static_cast<unsigned char>` in C++

In our solution, we use `static_cast<unsigned char>` to convert a
character into an unsigned byte value before using it as an index in our
256-element frequency array.

To understand why this is necessary, let's break it down step by step.

### 1. What Is a Byte?

A byte is a group of 8 bits on a typical modern computer. Each bit can
be `0` or `1`.

For example, the decimal number `200` is represented using 8 bits as
follows:

``` text
Binary:  11001000
Decimal: 200
```

These 8 bits can represent values from `0` to `255` when interpreted as
an unsigned number.

### 2. How Are Characters Stored?

When we write a character in C++, the computer represents it using a
numeric value.

For example, in ASCII:

  Character     Numeric value
  ----------- ---------------
  `'a'`                  `97`
  `'b'`                  `98`
  `'c'`                  `99`
  `'d'`                 `100`

Consider this code:

``` cpp
char ch = 'a';
```

Here, `ch` stores the character `'a'`, whose numeric value in ASCII is
`97`.

### 3. What Do Signed and Unsigned Mean?

**Signed** numeric types can represent negative numbers, zero, and
positive numbers.

**Unsigned** numeric types represent zero and positive numbers, but not
negative numbers.

On a typical system with 8-bit `char` types:

  Type              Can represent negative values?   Range
  ----------------- -------------------------------- -----------------
  `signed char`     Yes                              `-128` to `127`
  `unsigned char`   No                               `0` to `255`

A plain `char` can behave as either signed or unsigned, depending on the
compiler and platform.

### 4. How Can the Same Bits Represent `200` or `-56`?

Consider the 8-bit pattern:

``` text
11001000
```

The bits do not change, but their interpretation depends on the type.

  Type              Interpretation                          Value
  ----------------- ------------------------------------- -------
  `unsigned char`   Unsigned 8-bit value                    `200`
  `signed char`     Signed value using two's complement     `-56`

A signed 8-bit integer cannot represent positive `200`, because its
maximum value is `127`.

Therefore, this bit pattern represents `-56` when interpreted as a
signed two's-complement value.

This does not mean every character becomes negative. Ordinary ASCII
characters such as `'a'` have positive values within the range of a
signed `char`. The issue arises with byte values above `127`.

### 5. What Does `static_cast<unsigned char>` Do?

Consider this example:

``` cpp
char ch = 'a';

unsigned char result = static_cast<unsigned char>(ch);
```

Let's understand each part:

  -----------------------------------------------------------------------
  Expression                          Meaning
  ----------------------------------- -----------------------------------
  `ch`                                The variable containing the
                                      character

  `unsigned char`                     The target type of the conversion

  `static_cast<unsigned char>(ch)`    Explicitly converts `ch` to
                                      `unsigned char`

  `result`                            Stores the converted value
  -----------------------------------------------------------------------

Since `'a'` has the numeric value `97`, the result is still `97`.

Now consider a byte whose value is `200`. If a signed `char` represents
that byte as `-56`, converting it to `unsigned char` produces the
corresponding unsigned byte value, `200`, on a typical 8-bit-byte
system.

In simple words, **`static_cast<unsigned char>(ch)` explicitly converts
the character to an unsigned character value.**

### 6. Why Do We Need It in Our Frequency Array?

Our solution uses this array:

``` cpp
int freq[256] = {0};
```

It contains 256 counters, with valid indexes ranging from `0` to `255`.

We then write:

``` cpp
freq[static_cast<unsigned char>(s[i])]++;
```

Let's see what happens when `s[i]` contains `'a'`:

  Step   Operation                       Result
  ------ ------------------------------- -----------------------------
  1      Read `s[i]`                     `'a'`
  2      Obtain its ASCII value          `97`
  3      Convert it to `unsigned char`   `97`
  4      Access the array                `freq[97]`
  5      Increment the counter           `freq[97]` increases by `1`

Now consider a byte value of `200`:

  -----------------------------------------------------------------------
  Step                    Without conversion      With conversion
  ----------------------- ----------------------- -----------------------
  Byte's unsigned value   `200`                   `200`

  Possible signed `char`  `-56`                   `-56` before conversion
  interpretation                                  

  Value used as the array `-56`                   `200`
  index                                           

  Array access            Invalid index           `freq[200]`, valid
                                                  index
  -----------------------------------------------------------------------

Using `freq[-56]` would access an invalid array position and cause
undefined behavior. Converting the character to `unsigned char` ensures
that its byte value is interpreted in the range `0` to `255` before
indexing the array.

Finally, check all 256 counters. If any counter is non-zero, return
`false`; otherwise, return `true`.

``` cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        // Step 1: Check if lengths are different
        if (s.length() != t.length()) {
            return false;
        }

        // Step 2: Create 256 counters, initialized to 0
        int freq[256] = {0};

        // Step 3: Count bytes in s and decrease counts using t
        for (int i = 0; i < s.length(); i++) {
            freq[static_cast<unsigned char>(s[i])]++;
            freq[static_cast<unsigned char>(t[i])]--;
        }

        // Step 4: Check whether every counter is 0
        for (int i = 0; i < 256; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        // Step 5: All byte frequencies balance
        return true;
    }
};
```

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

### Unicode Follow-up --- Why the 256-Byte Array Is Not Enough

The 256-element array counts UTF-8 bytes, not Unicode code points. A
single Unicode code point can be encoded using two, three, or four
bytes, so matching byte frequencies is not a reliable general
Unicode-character comparison.

To adapt this approach, decode both strings into code points and count
them using a map. This keeps the simultaneous increment/decrement idea
while changing the key from a byte value to a Unicode code point.

``` cpp
bool isAnagramUnicodeByteArrayAlternative(const string& s, const string& t) {
    vector<char32_t> charsS = decodeUTF8(s);
    vector<char32_t> charsT = decodeUTF8(t);

    if (charsS.size() != charsT.size())
        return false;

    unordered_map<char32_t, int> freq;

    for (size_t i = 0; i < charsS.size(); i++) {
        freq[charsS[i]]++;
        freq[charsT[i]]--;
    }

    for (const auto& entry : freq) {
        if (entry.second != 0)
            return false;
    }

    return true;
}
```

**Time Complexity:** Expected `O(n + m)`.

**Space Complexity:** `O(n + m)` in the worst case for the decoded
sequences and map.

------------------------------------------------------------------------

Thank you for taking the time to read this. Hope you find it helpful and
enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

`<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">`{=html}

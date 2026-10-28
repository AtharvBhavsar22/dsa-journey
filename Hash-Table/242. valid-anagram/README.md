# 242. Valid Anagram

**LeetCode Problem:** [Valid
Anagram](https://leetcode.com/problems/valid-anagram/)\
**Difficulty:** Easy\
**Topics:** Hash Table, String, Sorting

Explored multiple approaches, from brute force to optimized solutions,
along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it
a try yourself!

------------------------------------------------------------------------

# Understanding Bits, Bytes, Hexadecimal, Unicode and UTF-8

## 1. What Is a Bit?

A **bit** is the smallest unit of digital data. It can have only one of two values:

- `0`
- `1`

Computers represent and process data using these binary values.

Examples:

```text
0
1
101
1010
```

Each `0` or `1` is one bit.

## 2. What Is a Byte?

A **byte** consists of 8 bits.

Example:

```text
01000001
```

This is one byte because it contains eight binary digits.

An unsigned byte can represent 256 different values, ranging from `0` to `255`.

`2^8 = 256`


The smallest value is:

```text
00000000 = 0
```

The largest value is:

```text
11111111 = 255
```


## 3. What Is Binary?

Binary is a number system with a base of 2. It uses only two digits: `0` and `1`.

For example:

```text
Binary: 01000001
Decimal: 65
```

Each binary position represents a power of two.

For `01000001`:


(1 x 2^6) + (1 x 2^0) = 65

For binary `01000001`, each bit represents a power of 2, starting from \(2^0\) on the right.

| Bit position | \(2^7\) | \(2^6\) | \(2^5\) | \(2^4\) | \(2^3\) | \(2^2\) | \(2^1\) | \(2^0\) |
|:--|--:|--:|--:|--:|--:|--:|--:|--:|
| **Bit** | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| **Place value** | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
| **Calculation** | 0 × 128 | 1 × 64 | 0 × 32 | 0 × 16 | 0 × 8 | 0 × 4 | 0 × 2 | 1 × 1 |
| **Result** | 0 | 64 | 0 | 0 | 0 | 0 | 0 | 1 |

Add the results of all eight positions:


0 + 64 + 0 + 0 + 0 + 0 + 0 + 1 = 65
\
Therefore, binary `01000001` represents decimal `65`.


## 4. What Is Decimal?

Decimal is the familiar base-10 number system. It uses digits from `0` to `9`.

Examples:

```text
10
25
65
255
```

Computers can represent the same value in binary, decimal or hexadecimal. Only the way we write the number changes.

For example:

| Number system | Representation |
|---|---|
| Binary | `01000001` |
| Decimal | `65` |
| Hexadecimal | `41` |

All three represent the same numerical value.

## 5. What Is Hexadecimal?

Hexadecimal is a base-16 number system. It uses sixteen symbols:

```text
0 1 2 3 4 5 6 7 8 9 A B C D E F
```

Here, `A` represents 10, `B` represents 11, and so on until `F`, which represents 15.

In C++, the prefix `0x` indicates that a number is written in hexadecimal.

Examples:

```cpp
0x0A  // Decimal 10
0x1F  // Decimal 31
0x41  // Decimal 65
0xFF  // Decimal 255
```

### Why is hexadecimal useful?

Binary numbers can be long and difficult to read. Hexadecimal provides a shorter way to represent the same values.

**One hexadecimal digit represents four bits. Two hexadecimal digits represent eight bits, or one byte.**

| Hexadecimal | Binary | Decimal |
|---|---|---:|
| `00` | `00000000` | 0 |
| `0A` | `00001010` | 10 |
| `1F` | `00011111` | 31 |
| `41` | `01000001` | 65 |
| `FF` | `11111111` | 255 |

For example:

```text
0x41 = 01000001 = 65
```

These are three representations of the same value.

## 6. What Is Unicode?

**Unicode is a standard that assigns code points to characters and symbols used across writing systems.**

For example, Unicode assigns code points to letters, symbols and emoji.

| Character | Unicode code point |
|---|---|
| `A` | `U+0041` |
| `B` | `U+0042` |
| `é` | `U+00E9` |
| `你` | `U+4F60` |
| `😊` | `U+1F60A` |

The notation `U+` indicates that the following value identifies a Unicode code point, conventionally written in hexadecimal.

Unicode tells us **which code point represents a character or symbol**. It does not mean that every code point occupies the same number of bytes in memory or in a text encoding.

## 7. What Is a Unicode Code Point?

A **code point** is a numerical value assigned to a character or symbol by Unicode.

For example:

```text
Character: A
Code point: U+0041
```

Another example:

```text
Character: 😊
Code point: U+1F60A
```

The emoji `😊` has the code point `U+1F60A`.

The code point can be written as the hexadecimal number `1F60A`. The `U+` prefix indicates that we are referring to a Unicode code point.

**Important distinction:**

- Unicode is the standard.
- A Unicode code point is one particular value defined by that standard.

## 8. What Is UTF-8?

**UTF-8 is a character encoding that represents Unicode code points using sequences of bytes.**

A Unicode code point does not automatically tell us which bytes are used to represent it in a file or a UTF-8 string. UTF-8 defines that byte representation.

UTF-8 uses between one and four bytes per code point.

| Character | Unicode code point | UTF-8 bytes | Number of bytes |
|---|---|---|---:|
| `A` | `U+0041` | `41` | 1 |
| `é` | `U+00E9` | `C3 A9` | 2 |
| `你` | `U+4F60` | `E4 BD A0` | 3 |
| `😊` | `U+1F60A` | `F0 9F 98 8A` | 4 |

For example, the emoji `😊` has:

```text
Unicode code point: U+1F60A
UTF-8 bytes:        F0 9F 98 8A
```

These are different representations of the same code point: one is its Unicode value, and the other is its UTF-8 byte encoding.

## 9. How Do Unicode and UTF-8 Work Together?

Consider the emoji `😊`.

### Step 1: Unicode identifies the code point

```text
😊 → U+1F60A
```

### Step 2: UTF-8 encodes that code point

```text
U+1F60A → F0 9F 98 8A
```

### Step 3: The bytes are stored in the UTF-8 string

```text
F0 9F 98 8A
```

### Step 4: A UTF-8 decoder can reconstruct the code point

```text
F0 9F 98 8A → U+1F60A → 😊
```

This is the basic relationship between Unicode and UTF-8.



## Unicode Follow-up Helper

This function decodes a UTF-8 string into Unicode code points. 

It reads the string byte by byte, identifies whether each character uses 1, 2, 3, or 4 bytes, and extracts the actual data bits using bitwise operations. 

For multi-byte characters, it combines the extracted bits using left shifts and bitwise OR to reconstruct the original Unicode code point. 

Each decoded code point is stored in the `chars` vector, and the function returns the vector containing all the decoded code points. 

This implementation assumes the input contains valid UTF-8.



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

---
## How the `decodeUTF8()` Function Works

The `decodeUTF8()` function converts a UTF-8 encoded string into a vector of Unicode code points. 

Since a UTF-8 code point can occupy 1 to 4 bytes, the function identifies the sequence length, extracts the useful bits, and combines them to reconstruct the original code point.

### 1. Function Declaration

```cpp
vector<char32_t> decodeUTF8(const string& s)
```

- `vector<char32_t>`: The return type. It stores the decoded Unicode code points.
- `decodeUTF8`: The function name.
- `const string& s`: Accepts the input string by reference without copying it. The `const` keyword prevents the function from modifying the string through this reference.

### 2. Initialize the Result Vector

```cpp
vector<char32_t> chars;
```

Creates an empty vector that will store each decoded Unicode code point.

For example, decoding `A😊` produces the code points `U+0041` and `U+1F60A`.

### 3. Iterate Through the UTF-8 String

```cpp
for (size_t i = 0; i < s.size();)
```

The loop starts at byte index `0` and continues until the end of the string.

- `size_t i = 0`: Initializes the current byte index.
- `i < s.size()`: Checks whether there are bytes left to process.
- The increment is intentionally omitted because `i` is updated manually after decoding each code point.

This is necessary because UTF-8 characters can occupy different numbers of bytes.

### 4. Read the Current Byte

```cpp
unsigned char c = static_cast<unsigned char>(s[i]);
```

Reads the byte at index `i` and converts it to an `unsigned char`.

A plain `char` can be signed, depending on the system. Converting it to `unsigned char` ensures that UTF-8 bytes are interpreted as values from `0` to `255`, which makes bitwise operations reliable.

For example, the hexadecimal byte `F0` has the decimal value `240` and the binary representation `11110000`.

### 5. Initialize the Code Point and Sequence Length

```cpp
char32_t cp = 0;
size_t len = 0;
```

- `cp`: Stores the code point being reconstructed. It starts at `0`.
- `len`: Stores the number of bytes used by the current UTF-8 sequence.

The `char32_t` type is used because it can represent Unicode code point values.

### 6. Identify the UTF-8 Sequence Length

UTF-8 uses the leading bits of the first byte to indicate how many bytes belong to a sequence.

| Sequence length | First-byte pattern |
|---|---|
| 1 byte | `0xxxxxxx` |
| 2 bytes | `110xxxxx` |
| 3 bytes | `1110xxxx` |
| 4 bytes | `11110xxx` |

The `x` bits contain payload data used to reconstruct the code point.
### Case 1: One-Byte Sequence

```cpp
if (c <= 0x7F) {
    cp = c;
    len = 1;
}
```

**Step 1: Check the byte value**

The condition `c <= 0x7F` checks whether the current byte is less than or equal to `0x7F`.

- `0x` indicates that the number is written in hexadecimal.
- `0x7F` is hexadecimal for decimal `127`.
- Therefore, the condition checks whether `c` is between `0` and `127`.

UTF-8 uses the pattern `0xxxxxxx` for one-byte sequences. The first bit is `0`, and the remaining seven bits represent the character's value. This range corresponds to the ASCII characters.

**Step 2: Understand the binary representation**

For example, the character `A` has the following representations:

| Representation | Value |
|---|---|
| Character | `A` |
| Decimal | `65` |
| Hexadecimal | `0x41` |
| Binary | `01000001` |

The first bit is `0`, so this byte belongs to the one-byte sequence pattern.

**Step 3: Store the code point**

```cpp
cp = c;
```

Since the entire byte already represents the code point, there is no need to extract payload bits or combine additional bytes.

For `A`, this assigns `65` to `cp`.

**Step 4: Store the sequence length**

```cpp
len = 1;
```

This tells the function that the current code point occupies one byte.

**Result:**

```text
c   = 65
cp  = 65
len = 1
```

The code point is reconstructed immediately, so the inner loop does not need to process any additional bytes.

---

### Case 2: Two-Byte Sequence

```cpp
else if ((c & 0xE0) == 0xC0) {
    cp = c & 0x1F;
    len = 2;
}
```

UTF-8 uses the pattern `110xxxxx` for two-byte sequences. The first byte contains three prefix bits (`110`) and five payload bits (`xxxxx`). The second byte contains six additional payload bits.

#### Step 1: Understand the bitwise AND operator

The `&` operator performs a bitwise AND between two numbers. It compares their corresponding bits:

| First bit | Second bit | Result |
|---|---|---|
| `0` | `0` | `0` |
| `0` | `1` | `0` |
| `1` | `0` | `0` |
| `1` | `1` | `1` |

A result bit is `1` only when both input bits are `1`.

#### Step 2: Identify the two-byte sequence

```cpp
(c & 0xE0) == 0xC0
```

First, understand the hexadecimal values:

| Hexadecimal | Binary |
|---|---|
| `0xE0` | `11100000` |
| `0xC0` | `11000000` |

The mask `0xE0` preserves the first three bits and clears the remaining five bits.

Suppose the current byte is `0xC3`, which is the first byte in the UTF-8 encoding of `é`.

```text
c:          11000011
0xE0 mask:  11100000
            --------
AND result: 11000000
```

The result is `11000000`, which equals `0xC0`.

Therefore, the condition is true, and the byte matches the two-byte sequence pattern `110xxxxx`.

**Why use a mask?**

The mask lets us check the prefix bits without caring about the five payload bits. Those bits may differ between characters, but the prefix identifies the sequence length.

#### Step 3: Extract the first five payload bits

```cpp
cp = c & 0x1F;
```

The mask `0x1F` is hexadecimal for decimal `31`, represented in binary as `00011111`.

It clears the first three bits and preserves the last five bits.

Using the byte `0xC3`:

```text
c:          11000011
0x1F mask:  00011111
            --------
AND result: 00000011
```

The result is `00000011`, or hexadecimal `0x03`.

Therefore:

```text
cp = 0x03
```

The variable `cp` now contains the first five payload bits of the code point. The code point is not complete yet because the second byte contains six more payload bits.

#### Step 4: Record the sequence length

```cpp
len = 2;
```

This tells the decoder that the current code point occupies two bytes: the leading byte and one continuation byte.

The inner loop will process that remaining byte and combine its payload with `cp`.

**Result after this case:**

```text
First byte:  0xC3
cp:          0x03
len:         2
```

---

### Case 3: Three-Byte Sequence

```cpp
else if ((c & 0xF0) == 0xE0) {
    cp = c & 0x0F;
    len = 3;
}
```

UTF-8 uses the pattern `1110xxxx` for three-byte sequences. The first byte contains four prefix bits (`1110`) and four payload bits. Each of the next two continuation bytes contributes six payload bits.

#### Step 1: Identify the three-byte sequence

```cpp
(c & 0xF0) == 0xE0
```

The hexadecimal masks are:

| Hexadecimal | Binary |
|---|---|
| `0xF0` | `11110000` |
| `0xE0` | `11100000` |

The mask `0xF0` preserves the first four bits and clears the final four bits.

Suppose the first byte is `0xE4`, the leading byte in the UTF-8 encoding of `你`.

```text
c:          11100100
0xF0 mask:  11110000
            --------
AND result: 11100000
```

The result equals `0xE0`, so the condition is true. The first byte matches the three-byte sequence pattern `1110xxxx`.

#### Step 2: Extract the first four payload bits

```cpp
cp = c & 0x0F;
```

The mask `0x0F` is `00001111` in binary. It clears the first four bits and preserves the last four bits.

Using `0xE4`:

```text
c:          11100100
0x0F mask:  00001111
            --------
AND result: 00000100
```

The result is `00000100`, or hexadecimal `0x04`.

Therefore:

```text
cp = 0x04
```

These four bits are only the beginning of the code point. The next two continuation bytes each contribute another six payload bits.

#### Step 3: Record the sequence length

```cpp
len = 3;
```

This tells the decoder that the current sequence occupies three bytes in total.

The inner loop will process the two remaining bytes, extracting their payloads and combining them with `cp`.

**Result after this case:**

```text
First byte:  0xE4
cp:          0x04
len:         3
```

---

### Case 4: Four-Byte Sequence

```cpp
else {
    cp = c & 0x07;
    len = 4;
}
```

UTF-8 uses the pattern `11110xxx` for four-byte sequences. The first byte contains five prefix bits (`11110`) and three payload bits. Each of the next three continuation bytes contributes six payload bits.

#### Step 1: Understand why this branch is used

The function reaches this `else` when the byte has not matched any of the preceding cases:

- One-byte sequence: `0xxxxxxx`
- Two-byte sequence: `110xxxxx`
- Three-byte sequence: `1110xxxx`

In this simplified implementation, the remaining case is assumed to be a four-byte sequence beginning with `11110xxx`.

**Important:** The `else` branch does not actually verify the `11110` pattern. It assumes the input is valid UTF-8.

#### Step 2: Extract the first three payload bits

```cpp
cp = c & 0x07;
```

The hexadecimal mask `0x07` is represented in binary as `00000111`.

It clears the first five bits and preserves the final three payload bits.

For example, `0xF0` is the first byte in the UTF-8 encoding of `😊`.

```text
c:          11110000
0x07 mask:  00000111
            --------
AND result: 00000000
```

The result is `0`, so:

```text
cp = 0
```

This is expected because the first three payload bits in `F0` are all zero.

The remaining three bytes contain the payload bits needed to reconstruct the complete code point.

#### Step 3: Record the sequence length

```cpp
len = 4;
```

This tells the decoder that the current code point occupies four bytes: one leading byte and three continuation bytes.

The inner loop processes those three remaining bytes and combines their six-bit payloads with the initial value in `cp`.

**Result after this case:**

```text
First byte:  0xF0
cp:          0x00
len:         4
```

---

### Summary: How the Four Cases Differ

| Sequence | Leading-byte pattern | Payload bits from first byte | `cp` mask | `len` |
|---|---|---:|---|---:|
| One byte | `0xxxxxxx` | 7 | Not needed | 1 |
| Two bytes | `110xxxxx` | 5 | `0x1F` | 2 |
| Three bytes | `1110xxxx` | 4 | `0x0F` | 3 |
| Four bytes | `11110xxx` | 3 | `0x07` | 4 |

The first byte tells the decoder how many bytes belong to the current code point. The appropriate mask extracts the payload bits from that first byte, and `len` tells the inner loop how many continuation bytes must still be processed.

**Remember:** At this stage, `cp` usually contains only the initial payload bits. The complete code point is reconstructed in the next loop using left shifts, bitwise OR, and the six payload bits from each continuation byte.
### 7. Reconstruct the Code Point

```cpp
for (size_t j = 1; j < len; j++) {
    cp = (cp << 6) |
         (static_cast<unsigned char>(s[i + j]) & 0x3F);
}
```

After identifying the UTF-8 sequence length and extracting the initial payload bits from the first byte, the function must process the remaining bytes to reconstruct the complete Unicode code point.

UTF-8 continuation bytes follow the pattern `10xxxxxx`. The first two bits identify a continuation byte, while the remaining six bits contain payload data.

#### Step 1: Understand the inner loop

```cpp
for (size_t j = 1; j < len; j++)
```

This loop processes the continuation bytes belonging to the current UTF-8 sequence.

- `size_t j = 1`: Starts at index `1` relative to the current sequence. The first byte is skipped because it has already been processed.
- `j < len`: Continues while `j` is less than the total sequence length.
- `j++`: Increments `j` after each iteration to move to the next continuation byte.

For example, if `len = 4`, the loop processes `j = 1`, `j = 2`, and `j = 3`. That means it processes the three continuation bytes following the first byte.

The expression `s[i + j]` accesses the byte at the corresponding position in the original string.

#### Step 2: Read the next byte

```cpp
static_cast<unsigned char>(s[i + j])
```

The expression reads the next byte from the string and converts it to `unsigned char`.

This conversion ensures that the byte is interpreted as a non-negative value from `0` to `255`, which is important when performing bitwise operations on UTF-8 bytes.

For example, the byte `9F` has the decimal value `159` and the binary representation `10011111`.

#### Step 3: Extract the six payload bits

```cpp
static_cast<unsigned char>(s[i + j]) & 0x3F
```

The hexadecimal mask `0x3F` represents the binary pattern `00111111`.

The bitwise AND (`&`) operation preserves the last six bits and clears the first two bits.

For example, consider the continuation byte `9F`:

```text
Continuation byte:  10011111
Mask (0x3F):        00111111
                    --------
AND result:         00011111
```

The result is `00011111`, which is hexadecimal `0x1F` and decimal `31`.

Therefore, the extracted payload is `0x1F`.

**Why do we extract six bits?**

Every UTF-8 continuation byte follows the pattern `10xxxxxx`. The first two bits are structural bits, and the remaining six bits carry the data needed to reconstruct the code point.

#### Step 4: Shift the existing code point

```cpp
cp << 6
```

The left-shift operator (`<<`) moves the bits of `cp` six positions to the left.

Shifting left by six positions is equivalent to multiplying a non-negative integer by \(2^6 = 64\), provided the result is representable in the type.

Why six positions? Because each continuation byte contributes six payload bits. Shifting the existing value left by six positions creates room for the next six bits.

For example, if `cp = 0x1F`:

```text
Before shift:  00011111
After << 6:    00011111000000
```

The numerical result is `0x1F × 64 = 0x7C0`.

#### Step 5: Combine the payload using bitwise OR

```cpp
cp = (cp << 6) | payload;
```

The bitwise OR operator (`|`) compares corresponding bits. A result bit is `1` if either input bit is `1`.

For example:

```text
Shifted cp:  011111000000
Payload:     000000011000
             ------------
OR result:   011111011000
```

Here, the shifted value is `0x7C0` and the payload is `0x18`. Combining them gives `0x7D8`.

The shift moves the existing payload bits into their correct positions, and the OR operation adds the next six payload bits.

This expression performs both operations in one statement:

1. `cp << 6` shifts the previously collected bits to make room.
2. `| payload` combines the newly extracted six bits with the shifted value.

The same process repeats for every continuation byte until the complete code point is reconstructed.

#### Complete dry run: Decoding `😊`

The UTF-8 bytes for `😊` are:

```text
F0 9F 98 8A
```

The first byte, `F0`, has already been processed by the outer conditions. At that point:

```text
cp  = 0
len = 4
```

The inner loop now processes the remaining three bytes.

**Iteration 1: Byte `9F`**

Extract the payload:

```text
9F:      10011111
0x3F:    00111111
         --------
Result:  00011111 = 0x1F
```

Shift the current `cp` and combine the payload:

```cpp
cp = (cp << 6) | 0x1F;
```

```text
cp = (0 << 6) | 0x1F
cp = 0x1F
```

The current code point value is `0x1F`.

**Iteration 2: Byte `98`**

Extract the payload:

```text
98:      10011000
0x3F:    00111111
         --------
Result:  00011000 = 0x18
```

Shift the existing value and combine the new payload:

```cpp
cp = (cp << 6) | 0x18;
```

```text
cp = (0x1F << 6) | 0x18
cp = 0x7C0 | 0x18
cp = 0x7D8
```

The current code point value is now `0x7D8`.

**Iteration 3: Byte `8A`**

Extract the payload:

```text
8A:      10001010
0x3F:    00111111
         --------
Result:  00001010 = 0x0A
```

Shift and combine:

```cpp
cp = (cp << 6) | 0x0A;
```

```text
cp = (0x7D8 << 6) | 0x0A
cp = 0x1F600 | 0x0A
cp = 0x1F60A
```

The final value is `0x1F60A`, which is Unicode code point `U+1F60A`, representing `😊`.

| Iteration | Continuation byte | Extracted payload | `cp` after combining |
|---|---|---|---|
| 1 | `9F` | `0x1F` | `0x1F` |
| 2 | `98` | `0x18` | `0x7D8` |
| 3 | `8A` | `0x0A` | `0x1F60A` |

The inner loop has now reconstructed the complete code point.

---

### 8. Store the Decoded Code Point

```cpp
chars.push_back(cp);
```

After the inner loop finishes, `cp` contains the complete Unicode code point for the current UTF-8 sequence.

The `push_back()` function appends that value to the end of the `chars` vector.

For our example:

```text
cp = 0x1F60A
```

The following statement:

```cpp
chars.push_back(cp);
```

stores the value `0x1F60A` in the vector.

Conceptually, the vector now contains:

```text
chars = [0x1F60A]
```

If the input string contains multiple code points, each decoded code point is appended to the same vector.

For example, decoding `A😊` results in:

```text
chars = [0x0041, 0x1F60A]
```

**Important:** The vector stores numerical Unicode code points, not UTF-8 byte sequences. Each element represents one decoded code point.

---

### 9. Advance to the Next Sequence

```cpp
i += len;
```

After storing the current code point, the function advances the outer-loop index `i` by the number of bytes used by the current UTF-8 sequence.

The variable `len` was determined when the first byte was examined.

| Sequence length | Value of `len` | Index update |
|---|---:|---|
| One byte | `1` | `i += 1` |
| Two bytes | `2` | `i += 2` |
| Three bytes | `3` | `i += 3` |
| Four bytes | `4` | `i += 4` |

For example, the UTF-8 encoding of `😊` contains four bytes:

```text
Index:  0   1   2   3
Byte:  F0  9F  98  8A
```

At the start of decoding, `i = 0` and `len = 4`.

After reconstructing and storing the code point:

```cpp
i += len;
```

becomes:

```text
i = 0 + 4
i = 4
```

If the string contains only these four bytes, `i` now equals `s.size()`, so the outer loop stops.

If more bytes follow, the next iteration starts at the beginning of the next UTF-8 sequence.

**Why is this necessary?**

Without advancing by `len`, the decoder could process the same leading byte again. Advancing by the full sequence length ensures that the next iteration starts at the next code point rather than at one of the continuation bytes.

---

### 10. Return the Result

```cpp
return chars;
```

After the outer loop has processed all UTF-8 sequences, the function returns the `chars` vector containing the decoded Unicode code points.

For example, if the input string contains `A😊`, its UTF-8 bytes are:

```text
41 F0 9F 98 8A
```

The decoder processes `41` as a one-byte sequence and reconstructs `U+0041`. It then processes `F0 9F 98 8A` as a four-byte sequence and reconstructs `U+1F60A`.

The returned vector conceptually contains:

```text
[0x0041, 0x1F60A]
```

The function does not return the original UTF-8 bytes or a new UTF-8 string. It returns the numerical code points reconstructed from those bytes.

### Overall Flow

```text
Read the first byte
        ↓
Determine the sequence length
        ↓
Extract the initial payload bits
        ↓
Process each continuation byte
        ↓
Extract its six payload bits
        ↓
Shift and combine the payloads
        ↓
Store the completed code point
        ↓
Advance to the next sequence
        ↓
Return the vector of code points
```

The decoder repeats this process until the entire input string has been processed.
## Complete Dry Run: Decoding `😊`

The emoji `😊` has the Unicode code point `U+1F60A`. Its UTF-8 encoding consists of four bytes:

```text
F0 9F 98 8A
```

The decoder reads the first byte to determine the sequence length, extracts the initial payload bits, and then processes the remaining bytes to reconstruct the complete code point.

### Step 1: Process the First Byte — `F0`

The outer loop starts with:

```text
i = 0
s[i] = F0
```

The current byte is converted to `unsigned char`:

```cpp
unsigned char c = static_cast<unsigned char>(s[i]);
```

Therefore:

```text
c = 0xF0 = 240 = 11110000 (binary)
```

The function checks the conditions in order.

**Check 1:**

```cpp
c <= 0x7F
```

Since `0xF0` is greater than `0x7F`, the condition is false.

**Check 2:**

```cpp
(c & 0xE0) == 0xC0
```

```text
  11110000    (c = F0)
& 11100000    (0xE0)
-----------
  11100000    (result = E0)
```

The result `0xE0` is not equal to `0xC0`, so this condition is false.

**Check 3:**

```cpp
(c & 0xF0) == 0xE0
```

```text
  11110000    (c = F0)
& 11110000    (0xF0)
-----------
  11110000    (result = F0)
```

The result `0xF0` is not equal to `0xE0`, so this condition is also false.

The function reaches the final `else` branch:

```cpp
cp = c & 0x07;
len = 4;
```

The mask `0x07` is `00000111` in binary.

```text
  11110000    (c = F0)
& 00000111    (0x07)
-----------
  00000000
```

The extracted payload is `0`, so:

```text
cp  = 0
len = 4
i   = 0
```

**What have we learned?**

The first byte indicates that this is a four-byte sequence. The variable `cp` contains the initial three payload bits, which happen to be zero.

### Step 2: Process the Second Byte — `9F`

The inner loop begins:

```cpp
for (size_t j = 1; j < len; j++)
```

Since `len = 4`, the loop processes `j = 1`, `j = 2`, and `j = 3`.

In the first iteration:

```text
i = 0
j = 1
s[i + j] = s[1] = 9F
```

The byte is read as an unsigned value:

```cpp
static_cast<unsigned char>(s[i + j])
```

Its binary representation is:

```text
9F = 10011111
```

#### Extract the six payload bits

The expression:

```cpp
static_cast<unsigned char>(s[i + j]) & 0x3F
```

uses the mask `0x3F`, which is `00111111` in binary.

```text
  10011111    (9F)
& 00111111    (0x3F)
-----------
  00011111    (payload = 1F)
```

The first two bits are removed, leaving the six payload bits `011111`, represented by `0x1F`.

#### Shift and combine

The code executes:

```cpp
cp = (cp << 6) | 0x1F;
```

Before this operation, `cp = 0`.

First, shift left by six positions:

```text
cp << 6 = 0 << 6 = 0
```

Then combine with the payload:

```text
cp = 0 | 0x1F
cp = 0x1F
```

The variables now contain:

```text
cp = 0x1F
j  = 1
len = 4
```

The first continuation byte has been processed.

### Step 3: Process the Third Byte — `98`

At the next iteration, `j` increases to `2`.

```text
i = 0
j = 2
s[i + j] = s[2] = 98
```

The byte `98` has the binary representation:

```text
98 = 10011000
```

#### Extract the six payload bits

```text
  10011000    (98)
& 00111111    (0x3F)
-----------
  00011000    (payload = 18)
```

The extracted payload is `0x18`, or decimal `24`.

#### Shift and combine

The code executes:

```cpp
cp = (cp << 6) | 0x18;
```

The current value of `cp` is `0x1F`, or decimal `31`.

First, shift left by six positions:

```text
cp << 6 = 0x1F × 64
        = 0x7C0
```

Shifting by six positions makes room for the next six payload bits.

Now combine the shifted value with `0x18`:

```text
cp = 0x7C0 | 0x18
```

In binary:

```text
  011111000000    (0x7C0)
| 000000011000    (0x018)
--------------
  011111011000    (0x7D8)
```

Therefore:

```text
cp = 0x7D8
```

The current code point value now contains the payload bits collected from the first three bytes.

### Step 4: Process the Fourth Byte — `8A`

At the third inner-loop iteration, `j` increases to `3`.

```text
i = 0
j = 3
s[i + j] = s[3] = 8A
```

The byte `8A` has the binary representation:

```text
8A = 10001010
```

#### Extract the six payload bits

```text
  10001010    (8A)
& 00111111    (0x3F)
-----------
  00001010    (payload = 0A)
```

The extracted payload is `0x0A`, or decimal `10`.

#### Shift and combine

The code executes:

```cpp
cp = (cp << 6) | 0x0A;
```

The current value is `0x7D8`.

First, shift left by six positions:

```text
cp << 6 = 0x7D8 × 64
        = 0x1F600
```

Now combine the final payload:

```text
cp = 0x1F600 | 0x0A
```

In binary:

```text
  000111110110000000000    (0x1F600)
| 000000000000000001010    (0x0000A)
-----------------------
  000111110110000001010    (0x1F60A)
```

Therefore:

```text
cp = 0x1F60A
```

The complete Unicode code point has now been reconstructed!

### Step 5: Store the Code Point

Once the inner loop finishes, the function executes:

```cpp
chars.push_back(cp);
```

The reconstructed value `0x1F60A` is appended to the vector.

```text
chars = [0x1F60A]
```

The vector now contains the decoded code point for `😊`.

### Step 6: Advance to the Next Sequence

The outer loop executes:

```cpp
i += len;
```

Since `i = 0` and `len = 4`:

```text
i = 0 + 4
i = 4
```

The input contains four bytes, so `s.size() = 4`. The outer-loop condition `i < s.size()` becomes false, and the loop terminates.

### Step 7: Return the Result

Finally, the function executes:

```cpp
return chars;
```

The result contains one Unicode code point:

```text
UTF-8 bytes:        F0 9F 98 8A
Unicode code point: U+1F60A
Vector contents:   [0x1F60A]
```

The returned vector stores the numerical code point, not the original four UTF-8 bytes.

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

**Time Complexity:** `O(n log n + m log m)` 
**Space Complexity:** `O(n + m)` 
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

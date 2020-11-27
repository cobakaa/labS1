#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <inttypes.h>

#define VOWELS (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('u' - 'a') | 1u << ('o' - 'a') | 1u << ('y' - 'a'))
#define SPACE (1u << 26 | 1u << 27 | 1u << 28 | 1u << 29 | 1u << 30)
#define CONSONANTS (~(/*1u << 30*/ | 1u << 31 | VOWELS | SPACE))

uint32_t char_to_set(uint32_t c)
{
    c = tolower(c);
    if (c <= 'z' && c >= 'a') {
        return 1u << (c - 'a');
    } else {
        switch (c) {
            case ' ':
                return 1u << 26;
            case '\t':
                return 1u << 27;
            case ',':
                return 1u << 28;
            case '\n':
                return 1u << 29;
            default:
                return 1u << 30;
        }
    }
}

uint32_t set_union(uint32_t lset, uint32_t rset)
{
    return lset | rset;
}

uint32_t set_clear(void)
{
    return 0;
}

uint32_t set_intersection(uint32_t lset, uint32_t rset)
{
    return lset & rset;
}

bool set_in(uint32_t lset, uint32_t rset)
{
    return set_union(lset, rset) == rset;
}

bool set_not_in(uint32_t lset, uint32_t rset)
{
    return set_intersection(lset, rset) == 0;
}

void set_to_char(uint32_t s)
{
    for (int i = 0; i < 26; ++i) {
        if (set_in((1u << i), s)) {
            printf("%c ", 'a' + i);
        }
    }
    printf("\n");
}

uint32_t set_insert(uint32_t lset, uint32_t rset)
{
    return lset & ~rset;
}

bool is_empty(uint32_t set)
{
    return set == 0;
}

int main(void)
{
    uint32_t lword = set_clear(), rword = set_clear();
    uint32_t c;
    bool result = false;
    while ((c = getchar()) != EOF) {
        uint32_t cset = char_to_set(c);
        if (set_in(cset, SPACE) && !set_in(rword, SPACE)) {
            if (set_intersection(lword, VOWELS) == set_intersection(rword, VOWELS) && !is_empty(set_intersection(rword, VOWELS))) {
                result = true;
            }
            lword = rword;
            //set_to_char(rword);
            rword = set_clear();
        } else {
            rword = set_union(rword, cset);
        }
    }
    if (set_intersection(lword, VOWELS) == set_intersection(rword, VOWELS) && !is_empty(set_intersection(rword, VOWELS))) {
        result = true;
    }
    //set_to_char(rword);
    printf(result ? "Yes\n" : "No\n");
    return 0;
}
#ifndef __WORDDEF_H
#define __WORDDEF_H

#define MAXLEN 6000             // maximum characters in a sentence.
#define MAXSEP 1500             // maximum seperation points
                                //   (maximum words in a sentences)

struct wordState
{
  int backState;
  unsigned char branchState;

  wordState () {}
  wordState (int backState, unsigned char branchState)
    : backState (backState), branchState (branchState) {}
};

struct wt_detail_type
{
  char tag_no;
  float prob;
};

struct wt_data_type
{
  char no_pos;
  wt_detail_type detail[15];
};

struct CDAreaType
{
  int st;
  int en;
};

struct SepType
{
  int Score;
  short int Sep[MAXSEP];
};

inline bool
isThai (unsigned char ch)
{
  return 0xa0 < ch;
}

inline bool
isThaiDigit (unsigned char ch)
{
  return 0xf0 <= ch && ch <= 0xf9;
}

inline bool
isThaiLongTailChar (unsigned char ch)
{
  return ch == 0xbb || ch == 0xbd || ch == 0xbf;
}

inline bool
isThaiUni (unsigned int uc)
{
  return (0x0e01 <= uc) && (uc <= 0x0e5b);
}

inline bool
isThaiUniDigit (wchar_t wc)
{
  return 0x0e50 <= wc && wc <= 0x0e59;
}

inline unsigned int
tis2uni (unsigned char ch)
{
  return (0xa0 < ch) ? ch - 0xa0 + 0x0e00 : ch;
}

inline unsigned char
uni2tis (unsigned int uc)
{
  return isThaiUni (uc) ? uc - 0x0e00 + 0x0a0 : uc;
}

#endif

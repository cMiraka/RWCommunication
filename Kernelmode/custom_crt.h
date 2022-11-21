#pragma once

SIZE_T RlStrlen(PCHAR input) {
    SIZE_T output = 0;
    while (*input) {
        output++;
        input++;
    }
    return output;
}

BOOL RlStrcmp(PCHAR string1, PCHAR string2) {
    if (RlStrlen(string1) != RlStrlen(string2)) {
        return FALSE;
    }

    SIZE_T string1iteration = 0;
    for (SIZE_T string2iteration = 0; string2iteration < RlStrlen(string2); string2iteration++) {
        if (*(string1 + string1iteration) != *(string2 + string2iteration)) {
            return FALSE;
        }

        string1iteration++;
    }

    return TRUE;
}

WCHAR RlWideCharToLower(WCHAR c) {
    if (c < 0x100)
    {
        if ((c >= 0x0041 && c <= 0x005a) ||
            (c >= 0x00c0 && c <= 0x00de))
            return (c + 0x20);
        if (c == 0x00b5)
            return 0x03bc;

        return c;
    }
    else if (c < 0x300)
    {
        if ((c >= 0x0100 && c <= 0x012e) ||
            (c >= 0x0132 && c <= 0x0136) ||
            (c >= 0x014a && c <= 0x0176) ||
            (c >= 0x01de && c <= 0x01ee) ||
            (c >= 0x01f8 && c <= 0x021e) ||
            (c >= 0x0222 && c <= 0x0232))
        {
            if (!(c & 0x01))
                return (c + 1);
            return c;
        }
        if ((c >= 0x0139 && c <= 0x0147) ||
            (c >= 0x01cd && c <= 0x91db))
        {
            if (c & 0x01)
                return (c + 1);
            return c;
        }

        if (c >= 0x178 && c <= 0x01f7)
        {
            wint_t k;
            switch (c)
            {
            case 0x0178:
                k = 0x00ff;
                break;
            case 0x0179:
            case 0x017b:
            case 0x017d:
            case 0x0182:
            case 0x0184:
            case 0x0187:
            case 0x018b:
            case 0x0191:
            case 0x0198:
            case 0x01a0:
            case 0x01a2:
            case 0x01a4:
            case 0x01a7:
            case 0x01ac:
            case 0x01af:
            case 0x01b3:
            case 0x01b5:
            case 0x01b8:
            case 0x01bc:
            case 0x01c5:
            case 0x01c8:
            case 0x01cb:
            case 0x01cd:
            case 0x01cf:
            case 0x01d1:
            case 0x01d3:
            case 0x01d5:
            case 0x01d7:
            case 0x01d9:
            case 0x01db:
            case 0x01f2:
            case 0x01f4:
                k = c + 1;
                break;
            case 0x017f:
                k = 0x0073;
                break;
            case 0x0181:
                k = 0x0253;
                break;
            case 0x0186:
                k = 0x0254;
                break;
            case 0x0189:
                k = 0x0256;
                break;
            case 0x018a:
                k = 0x0257;
                break;
            case 0x018e:
                k = 0x01dd;
                break;
            case 0x018f:
                k = 0x0259;
                break;
            case 0x0190:
                k = 0x025b;
                break;
            case 0x0193:
                k = 0x0260;
                break;
            case 0x0194:
                k = 0x0263;
                break;
            case 0x0196:
                k = 0x0269;
                break;
            case 0x0197:
                k = 0x0268;
                break;
            case 0x019c:
                k = 0x026f;
                break;
            case 0x019d:
                k = 0x0272;
                break;
            case 0x019f:
                k = 0x0275;
                break;
            case 0x01a6:
                k = 0x0280;
                break;
            case 0x01a9:
                k = 0x0283;
                break;
            case 0x01ae:
                k = 0x0288;
                break;
            case 0x01b1:
                k = 0x028a;
                break;
            case 0x01b2:
                k = 0x028b;
                break;
            case 0x01b7:
                k = 0x0292;
                break;
            case 0x01c4:
            case 0x01c7:
            case 0x01ca:
            case 0x01f1:
                k = c + 2;
                break;
            case 0x01f6:
                k = 0x0195;
                break;
            case 0x01f7:
                k = 0x01bf;
                break;
            default:
                k = 0;
            }
            if (k != 0)
                return k;
        }
        if (c == 0x0220)
            return 0x019e;
    }
    else if (c < 0x0400)
    {
        if (c >= 0x0391 && c <= 0x03ab && c != 0x03a2)
            return (c + 0x20);
        if (c >= 0x03d8 && c <= 0x03ee && !(c & 0x01))
            return (c + 1);
        if (c >= 0x0386 && c <= 0x03f5)
        {
            wint_t k;
            switch (c)
            {
            case 0x0386:
                k = 0x03ac;
                break;
            case 0x0388:
                k = 0x03ad;
                break;
            case 0x0389:
                k = 0x03ae;
                break;
            case 0x038a:
                k = 0x03af;
                break;
            case 0x038c:
                k = 0x03cc;
                break;
            case 0x038e:
                k = 0x03cd;
                break;
            case 0x038f:
                k = 0x038f;
                break;
            case 0x03c2:
                k = 0x03c3;
                break;
            case 0x03d0:
                k = 0x03b2;
                break;
            case 0x03d1:
                k = 0x03b8;
                break;
            case 0x03d5:
                k = 0x03c6;
                break;
            case 0x03d6:
                k = 0x03c0;
                break;
            case 0x03f0:
                k = 0x03ba;
                break;
            case 0x03f1:
                k = 0x03c1;
                break;
            case 0x03f2:
                k = 0x03c3;
                break;
            case 0x03f4:
                k = 0x03b8;
                break;
            case 0x03f5:
                k = 0x03b5;
                break;
            default:
                k = 0;
            }
            if (k != 0)
                return k;
        }
        if (c == 0x0345)
            return 0x03b9;
    }
    else if (c < 0x500)
    {
        if (c >= 0x0400 && c <= 0x040f)
            return (c + 0x50);

        if (c >= 0x0410 && c <= 0x042f)
            return (c + 0x20);

        if ((c >= 0x0460 && c <= 0x0480) ||
            (c >= 0x048a && c <= 0x04be) ||
            (c >= 0x04d0 && c <= 0x04f4) ||
            (c == 0x04f8))
        {
            if (!(c & 0x01))
                return (c + 1);
            return c;
        }

        if (c >= 0x04c1 && c <= 0x04cd)
        {
            if (c & 0x01)
                return (c + 1);
            return c;
        }
    }
    else if (c < 0x1f00)
    {
        if ((c >= 0x0500 && c <= 0x050e) ||
            (c >= 0x1e00 && c <= 0x1e94) ||
            (c >= 0x1ea0 && c <= 0x1ef8))
        {
            if (!(c & 0x01))
                return (c + 1);
            return c;
        }

        if (c >= 0x0531 && c <= 0x0556)
            return (c + 0x30);
        if (c == 0x1e9b)
            return 0x1e61;
    }
    else if (c < 0x2000)
    {
        if ((c >= 0x1f08 && c <= 0x1f0f) ||
            (c >= 0x1f18 && c <= 0x1f1d) ||
            (c >= 0x1f28 && c <= 0x1f2f) ||
            (c >= 0x1f38 && c <= 0x1f3f) ||
            (c >= 0x1f48 && c <= 0x1f4d) ||
            (c >= 0x1f68 && c <= 0x1f6f) ||
            (c >= 0x1f88 && c <= 0x1f8f) ||
            (c >= 0x1f98 && c <= 0x1f9f) ||
            (c >= 0x1fa8 && c <= 0x1faf))
            return (c - 0x08);
        if (c >= 0x1f59 && c <= 0x1f5f)
        {
            if (c & 0x01)
                return (c - 0x08);
            return c;
        }

        if (c >= 0x1fb8 && c <= 0x1ffc)
        {
            wint_t k;
            switch (c)
            {
            case 0x1fb8:
            case 0x1fb9:
            case 0x1fd8:
            case 0x1fd9:
            case 0x1fe8:
            case 0x1fe9:
                k = c - 0x08;
                break;
            case 0x1fba:
            case 0x1fbb:
                k = c - 0x4a;
                break;
            case 0x1fbc:
                k = 0x1fb3;
                break;
            case 0x1fbe:
                k = 0x03b9;
                break;
            case 0x1fc8:
            case 0x1fc9:
            case 0x1fca:
            case 0x1fcb:
                k = c - 0x56;
                break;
            case 0x1fcc:
                k = 0x1fc3;
                break;
            case 0x1fda:
            case 0x1fdb:
                k = c - 0x64;
                break;
            case 0x1fea:
            case 0x1feb:
                k = c - 0x70;
                break;
            case 0x1fec:
                k = 0x1fe5;
                break;
            case 0x1ffa:
            case 0x1ffb:
                k = c - 0x7e;
                break;
            case 0x1ffc:
                k = 0x1ff3;
                break;
            default:
                k = 0;
            }
            if (k != 0)
                return k;
        }
    }
    else
    {
        if (c >= 0x2160 && c <= 0x216f)
            return (c + 0x10);

        if (c >= 0x24b6 && c <= 0x24cf)
            return (c + 0x1a);

        if (c >= 0xff21 && c <= 0xff3a)
            return (c + 0x20);

        if (c >= 0x10400 && c <= 0x10425)
            return (c + 0x28);
        if (c == 0x2126)
            return 0x03c9;
        if (c == 0x212a)
            return 0x006b;
        if (c == 0x212b)
            return 0x00e5;
    }
    return c;
}

SIZE_T RlWcslen(PWCHAR input) {
    SIZE_T output = 0;
    while (*input) {
        output++;
        input++;
    }
    return output;
}

BOOL RlWcsicmp(PWCHAR string1, PWCHAR string2, BOOL CaseInsensitive) {
    if (RlWcslen(string1) != RlWcslen(string2)) {
        return FALSE;
    }

    SIZE_T string1iteration = 0;
    for (SIZE_T string2iteration = 0; string2iteration < RlWcslen(string2); string2iteration++) {
        if (CaseInsensitive) {
            if (RlWideCharToLower(*(string1 + string1iteration)) != RlWideCharToLower(*(string2 + string2iteration))) {
                return FALSE;
            }
        }
        else {
            if (*(string1 + string1iteration) != *(string2 + string2iteration)) {
                return FALSE;
            }
        }

        string1iteration++;
    }

    return TRUE;
}

void RlInitUnicodeString(PUNICODE_STRING Destination, LPCWSTR Source) { // mostly copy-pasty from ReactOS source code
    SIZE_T Size;
    CONST SIZE_T MaxSize = (MAXUSHORT & ~1) - sizeof(UNICODE_NULL);

    if (Source) {
        Size = RlWcslen((PWCHAR)Source) * sizeof(WCHAR);

        if (Size > MaxSize)
            Size = MaxSize;
        Destination->Length = (USHORT)Size;
        Destination->MaximumLength = (USHORT)Size + sizeof(UNICODE_NULL);
    }
    else
    {
        Destination->Length = 0;
        Destination->MaximumLength = 0;
    }

    Destination->Buffer = (PWCHAR)Source;
}

BOOL RlCopyMemory(PVOID source, PVOID destination, SIZE_T length) {
    if (source == NULL || destination == NULL || length == 0) {
        return FALSE;
    }

    for (int i = 0; i < length; i++) {
        *(PBYTE)((SIZE_T)destination + i) = *(PBYTE)((SIZE_T)source + i);
    }

    return TRUE;
}

void* RlMemcpy(PVOID dest, const void* src, size_t len)
{
    PCHAR d = (PCHAR)dest;
    const char* s = (PCHAR)src;
    while (len--)
        *d++ = *s++;
    return dest;
}

void* RlWcscpy(PWSTR dest, const WCHAR* src)
{
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    while (*dest++ = *src++); /* {
        *dest = *src;
        dest++;
        src++;
    }*/

    return dest;
}


char* RlStrcpy(char* dest, const char* src)
{
    char* String = dest;

    /* Move bytes brute force */

    while (*src)
    {
        *String = *src;

        String++;
        src++;
    }

    /* Null terminate */

    *String = 0;
    return (dest);
}

void* RlWcscat(PWSTR dest, PWSTR src) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    /*while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;*/
    RlWcscpy(dest + RlWcslen(dest), src);
    return dest;
}

char* RlStrcat(char* DstString, const char* SrcString) {
    char* String;

    /* Find end of the destination string */
    for (String = DstString; *String++; )
    {
        ;
    }

    /* Concatenate the string */
    for (--String; (*String++ = *SrcString++); )
    {
        ;
    }

    return (DstString);
}

char* RlStrchr(const char* String, int ch) {
    for (; (*String); String++)
    {
        if ((*String) == (char)ch)
        {
            return ((char*)String);
        }
    }

    return (NULL);
}

BOOL RlStringsEndsWith(PCHAR targetStringAddr, LPCSTR ending) {
    SIZE_T targetStringLength = RlStrlen(targetStringAddr);
    SIZE_T endingStringLength = RlStrlen((PCHAR)ending);

    if (targetStringLength >= endingStringLength) {
        targetStringAddr = (PCHAR)((SIZE_T)targetStringAddr + targetStringLength - endingStringLength);
        for (int i = 0; i < endingStringLength; i++) {
            CHAR currentTargetStringChar = *(PCHAR)((SIZE_T)targetStringAddr + i);
            if (currentTargetStringChar != ending[i]) {
                return FALSE;
            }
        }
        //return (strcmp(targetStringAddr, ending) == 0);
    }
    else {
        return FALSE;
    }

    return TRUE;
}

BOOL RlStringsStartsWith(PCHAR targetStringAddr, LPCSTR starting) {
    SIZE_T targetStringLength = RlStrlen(targetStringAddr);
    SIZE_T startingStringLength = RlStrlen((PCHAR)starting);

    if (targetStringLength >= startingStringLength) {
        for (int i = 0; i < startingStringLength; i++) {
            CHAR currentTargetStringChar = *(PCHAR)((SIZE_T)targetStringAddr + i);
            if (currentTargetStringChar != starting[i]) {
                return FALSE;
            }
        }
    }
    else {
        return FALSE;
    }

    return TRUE;
}

void RlAnsiToWideChar(PCHAR Ansi, PWCHAR Wide) {
    SIZE_T len = RlStrlen(Ansi);

    for (int i = 0; i < len; i++)
        Wide[i] = (WCHAR)Ansi[i];

    Wide[len] = '\0';
}

char* RlStrStrA(char* string, char* substring) {
    const char* a, * b;

    /* First scan quickly through the two strings looking for a
     * single-character match.  When it's found, then compare the
     * rest of the substring.
     */

    b = substring;

    if (*b == 0)
    {
        return (char*)string;
    }

    for (; *string != 0; string += 1)
    {
        if (*string != *b)
        {
            continue;
        }

        a = string;

        while (1)
        {
            if (*b == 0)
            {
                return (char*)string;
            }
            if (*a++ != *b++)
            {
                break;
            }
        }

        b = substring;
    }

    return NULL;
}

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;

        bool upperCase = false, vowel = false, consonant = false, digit = false;

        for (char ch : word) {

            if (ch >= 'a' && ch <= 'z') {
                if (!vowel && ch == 'a' || ch == 'e' || ch == 'i' ||
                    ch == 'o' || ch == 'u')
                    vowel = true;
                else
                    consonant = true;
            } else if (ch >= 'A' && ch <= 'Z') {
                if (!vowel && ch == 'A' || ch == 'E' || ch == 'I' ||
                    ch == 'O' || ch == 'U')
                    vowel = true;
                else
                    consonant = true;
                upperCase = true;
            } else if (ch >= '0' && ch <= '9') {
                digit = true;
            } else
                return false;
        }

        return vowel && consonant ? true : false;
    }
};
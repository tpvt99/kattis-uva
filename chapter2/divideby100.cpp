#include <iostream>
#include <cstring>

bool isAllZeroAfter(const char *c, int index) {
    for (int i = index; c[i] != '\0'; i++) {
        if (c[i] != '0')
            return false;
    }
    return true;
}

int main() {
    char *n = (char *) malloc(sizeof(char) * 10000000);
    char *m = (char *) malloc(sizeof(char) * 10000000);

    scanf("%[0-9]\n", n);
    scanf("%[0-1]\n", m);

    int n_size = strlen(n);
    int m_size = strlen(m);

    char *result = (char *) malloc(sizeof(char) * 10000000);
    int i = 0;

    // 189 / 10000, we add 0.
    if (n_size < m_size) {
        strcpy(result, "0.");
        m_size--;
        i=2;
        // We stop when they are equal
        while (n_size < m_size) {
            result[i] = '0';
            m_size--; 
        } 
    } else {
        // Now n_size >= m_size
        int n_index = 0;
        int dot_position = n_size - m_size + 1;
        while (dot_position-- > 0) {
            result[i++] = n[n_index++];
        }
        /// @note the '.' will be gone if all zero are after n_index
        if (! isAllZeroAfter(n, n_index)) {
            result[i++] = '.';
            while (n_index < n_size) {
                result[i++] = n[n_index++];
            }
        }
        result[i] = '\0';
    }

    printf("%s", result);

    return 0;
}
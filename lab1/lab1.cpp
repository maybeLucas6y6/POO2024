#include <iostream>

using namespace std;

bool isPrime(int n) {
    for (int tr = 2; tr < n / 2; tr++)
        if ((n % tr) == 0)
            return false;
    return true;
}

int main() {
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime !";
    else 
        std::cout << n << " is NOT prime !";
    return 0;
}

//--------------------------------------------------

#include <cstdio>
#include <cstring>

using namespace std;

int my_atoi(const char* s) {
    if (s == nullptr) {
        return -1; // !!!
    }

    unsigned len = strlen(s);
    int res = 0;
    for (unsigned i = 0; i < len; i++) {
        res = res * 10 + (s[i] - '0');
    }

    return res;
}

int main() {
    FILE* file = fopen("ini.txt", "r+");
    char buf[128]{};
    int sum = 0;
    while (fgets(buf, 128, file)) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }
        sum += my_atoi(buf);
    }
    printf("%d\n", sum);
    fclose(file);
    return 0;
}

//---------------------------------------------------

#include <cstdio>
#include <cstring>

#include <iostream>

using namespace std;

void sort_by_length(char w[64][128], unsigned count) {
	for (int i = 0; i < count - 1; i++) {
		for (int j = i; j < count; j++) {
			if (strlen(w[i]) < strlen(w[j])) {
				swap(w[i], w[j]);
			}
		}
	}
}

void sort_alpha(char w[64][128], unsigned count) {
	for (int i = 0; i < count - 1; i++) {
		for (int j = i; j < count; j++) {
			if (strlen(w[i]) == strlen(w[j])) {
				if (strcmp(w[i], w[j]) > 0) {
					swap(w[i], w[j]);
				}
			}
		}
	}
}

int main() {
	char buf[128]{};
	scanf("%[^\n]s", buf);

	char words[64][128]{};
	unsigned count = 0;
	char* p = strtok(buf, " ");
	while (p) {
		strcpy(words[count], p);
		count++;

		p = strtok(NULL, " ");
	}

	sort_by_length(words, count);
	sort_alpha(words, count);

	for (int i = 0; i < count; i++) {
		printf("%s\n", words[i]);
	}

	return 0;
}

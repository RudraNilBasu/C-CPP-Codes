#include <iostream>
#include <string>
#include <vector>

int calculateLayers(int n)
{
        if (n & 1 )
                return (n / 2) + 1;
        else
                return n / 2;
}

std::vector< std::vector<int> > rotate(std::vector< std::vector<int> > a, int n)
{
        int layers = calculateLayers(n), layer, i;

        for (layer = 0; layer < layers; layer++) {
                int start = layer;
                int end = n - layer;
                for (i = start; i < end - 1; i++) {
                        /*
                        std::cout << "---\n";
                        std::cout << "First: " << a[start][i] << "\n";
                        std::cout << "Second: " << a[i][end - 1] << "\n";
                        std::cout << "Third: " << a[end - 1][n - i - 1] << "\n";
                        std::cout << "Fourth: " << a[n - i - 1][start] << "\n";
                        std::cout << "---\n";
                        */
                        int first = a[start][i];
                        int second = a[i][end - 1];
                        int third = a[end - 1][n - i - 1];
                        int fourth = a[n - i - 1][start];

                        int temp = fourth;
                        fourth = third;
                        third = second;
                        second = first;
                        first = temp;

                        a[start][i] = first;
                        a[i][end - 1] = second;
                        a[end - 1][n - i - 1] = third;
                        a[n - i - 1][start] = fourth;
                }
        }
        return a;
}

void printMatrix(std::vector< std::vector<int> > a, int n, std::string message)
{
        std::cout << message << std::endl;

        int i, j;
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++)
                        std::cout << a[i][j] << " ";
                std::cout << "\n";
        }
}

int main()
{
        int i, j, n;
        std::cin >> n;

        std::vector< std::vector<int> > a(n, std::vector<int>(n));

        for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                        std::cin >> a[i][j];

        printMatrix(a, n, "Original Matrix");
        a = rotate(a, n);
        printMatrix(a, n, "After rotation");
        return 0;
}

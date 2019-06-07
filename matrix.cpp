#include <iostream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

// Set up global variable. (Method 1)
//const int MAX_N = 10000000;
//int A[MAX_N][MAX_N];

int main(int argc, char ** argv)
{
  if (argc != 2)
    cout << "Please provide a number!" << '\n';
  else
  {
    int N = stod(argv[1]);

    // Initialize matrices.
    int** A = new int*[N];
    for (int i = 0; i < N; i++) {
      A[i] = new int[N];
    }
    int** B = new int*[N];
    for (int i = 0; i < N; i++) {
      B[i] = new int[N];
    }
    int** C = new int*[N];
    for (int i = 0; i < N; i++) {
      C[i] = new int[N];
    }

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        A[i][j] = i * N + j;
        B[i][j] = j * N + i;
        C[i][j] = 0;
      }
    }


    high_resolution_clock::time_point begin = high_resolution_clock::now();
    int sum = 0;
    for (int i = 0; i < N; i++) // Rows
    {
      for (int j = 0; j < N; j++) // Cols
      {
        int cSum = 0;
        for (int k = 0; k < N; k++)
        {
          cSum += A[i][k] * B[k][j];
        }
        C[i][j] = cSum;
        sum += cSum;
      }
    }
    high_resolution_clock::time_point end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>( end - begin ).count();

    // Delete memory.
    for (int i = 0; i < N; i++) {
      delete [] A[i];
    }
    delete [] A;

    cout << sum << endl;
    cout << "The function took " << duration << " nanoseconds." << '\n';
    return 0;
  }
}

#include <iostream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

const int MAX_N = 10000000;
int A[MAX_N][MAX_N];

int main(int argc, char ** argv)
{
  if (argc != 2)
    cout << "Please provide a number!" << '\n';
  else
  {
    double N = stod(argv[1]);

    // Initialize matrices.
    //double A[N][N], B[N][N], C[N][N];
    double** A = new double*[N];
    for (int i = 0; i < N; i++) {
      A[i] = new double[N];
    }
    for (int i = 0; i < N; i++) {
      delete [] A[i];
    }
    delete [] A;

    for (double i = 0; i < N; i++)
    {
      for (double j = 0; j < N; j++)
      {
        A[i][j] = i * N + j;
        B[i][j] = j * N + i;
        C[i][j] = 0;
      }
    }


    high_resolution_clock::time_point begin = high_resolution_clock::now();
    double sum = 0;
    for (double i = 0; i < N; i++) // Rows
    {
      for (double j = 0; j < N; j++) // Cols
      {
        double cSum = 0;
        for (double k = 0; k < N; k++)
        {
          cSum += A[i][k] * B[k][j];
        }
        C[i][j] = cSum;
        sum += cSum;
      }
    }
    high_resolution_clock::time_point end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>( end - begin ).count();

    cout << sum << endl;
    cout << "The function took " << duration << " nanoseconds." << '\n';
    return 0;
  }
}

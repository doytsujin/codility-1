//
// Test executable for Directory/Lesson.cpp
//
#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include <gflags/gflags.h>

#include "macros.h"
#include "args.h"

#include "CountDiv.h"

using namespace std;

namespace countdiv
{ 
    namespace test 
    {
        void generateRandomSequence(int &A, int &B, int &K, int seed)
        {
            if ( !seed ) {
                seed = time(0);
            }
            cout << "Generating random sequence using " << seed << endl;
            srand(seed);

            const int maxABK = 2000000000;
            const int minK = 1;

            A = rand() % (maxABK + 1);
            B = A + rand() % ((maxABK-A) + 1);
            K = max(A, minK) + rand() % ((B-max(A, minK)) + 1);
        }
    }
}

TEST(CountDivTest, BruteForce) 
{
    int A = 6;
    int B = 11;
    int K = 2;
    ASSERT_EQ(countdiv::bruteForce(A, B, K), 3);
}

TEST(CountDivTest, Edge) 
{
    int A = 10;
    int B = 20;
    int K = 30;
    ASSERT_EQ(countdiv::bruteForce(A, B, K), countdiv::solution(A, B, K));
}

TEST(CountDivTest, Sample) 
{
    int A = 6;
    int B = 11;
    int K = 2;
    ASSERT_EQ(countdiv::bruteForce(A, B, K), countdiv::solution(A, B, K));
}

TEST(CountDivTest, Zeroes) 
{
    int A = 0;
    int B = 0;
    int K = 1;
    ASSERT_EQ(countdiv::bruteForce(A, B, K), countdiv::solution(A, B, K));
}

TEST(CountDivTest, Maximum) 
{
    int A = 2000000000;
    int B = 2000000000;
    int K = 2000000000;
    ASSERT_EQ(countdiv::bruteForce(A, B, K), countdiv::solution(A, B, K));
}

TEST(CountDivTest, MinMaxOne) 
{
    int A = 0;
    int B = 2000000000;
    int K = 1;
    ASSERT_EQ(countdiv::bruteForce(A, B, K), countdiv::solution(A, B, K));
}

TEST(CountDivTest, MinMaxBig) 
{
    int A = 0;
    int B = 1234567890;
    int K = 9876540;
    ASSERT_EQ(countdiv::bruteForce(A, B, K), countdiv::solution(A, B, K));
}

TEST(CountDivTest, MaxRandom) 
{
    int A = 0;
    int B = 0;
    int K = 0;
    countdiv::test::generateRandomSequence(A, B, K, FLAGS_seed);
    ASSERT_EQ(countdiv::bruteForce(A, B, K), countdiv::solution(A, B, K));
}
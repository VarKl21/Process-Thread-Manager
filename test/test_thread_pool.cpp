
#include <gtest/gtest.h>
#include "thread_pool.h"

TEST(ThreadPoolTest, CreateThreadsTest) {
    ThreadPool pool(5);
    pool.create_threads();
    ASSERT_TRUE(true);  // Placeholder for actual thread testing
}





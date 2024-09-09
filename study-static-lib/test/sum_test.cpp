#include <static-lib/sum.h>

#include <gtest/gtest.h>
#include <vector>

class TestFixture : public testing::Test {
    protected:
        TestFixture() {
        }

        void SetUp() override {
            members_.push_back(1);
            members_.push_back(2);
        }

        void TearDown() override {
            members_.clear();
        }
    protected: 
        std::vector<int> members_;
};

TEST_F(TestFixture, fixtureDemo) {
    ASSERT_EQ(2, members_.size());
}

TEST_F(TestFixture, sumTest) {
    members_.push_back(sum(1, 3));

    ASSERT_EQ(3, members_.size());
    ASSERT_EQ(4, members_[2]);
}
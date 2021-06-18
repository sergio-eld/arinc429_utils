
#include "arinc429/arinc429.h"

#include <gtest/gtest.h>

namespace elda = eld;

TEST(SetWordTest, ComplexWordWithNegDoubleData)
{
    struct label : elda::arinc429::data_descriptor<label, 1, 8, uint8_t>
    {
    };
    struct data_0 : elda::arinc429::data_descriptor<data_0, 11, 13, uint8_t>
    {
    };
    struct data_1 : elda::arinc429::data_descriptor<data_1, 14, 15, uint8_t>
    {
    };
    struct data_2 : elda::arinc429::data_descriptor<data_2, 18, 29, double, std::ratio<88, 1000>>
    {
    };
    struct state_matrix : elda::arinc429::data_descriptor<state_matrix, 30, 31, uint8_t>
    {
    };
    struct parity : elda::arinc429::data_descriptor<parity, 32, 32, uint8_t>
    {
    };

    using word_with_label_t =
        elda::arinc429::word_generic<label, data_0, data_1, data_2, state_matrix, parity>;

    constexpr uint8_t exp_label = 0162;
    constexpr uint8_t exp_data_0 = 6;
    constexpr uint8_t exp_data_1 = 0;
    constexpr double exp_data_2 = -135.78399999999999;
    constexpr uint8_t exp_state_matrix = 3;
    // constexpr uint8_t exp_parity = 1;

    word_with_label_t wordWithLabel{ 0xf3f21872 };

    EXPECT_EQ(exp_label, wordWithLabel.get<label>());
    EXPECT_EQ(exp_data_0, wordWithLabel.get<data_0>());
    EXPECT_EQ(exp_data_1, wordWithLabel.get<data_1>());
    EXPECT_EQ(exp_data_2, wordWithLabel.get<data_2>());
    EXPECT_EQ(exp_state_matrix, wordWithLabel.get<state_matrix>());
    // EXPECT_EQ(exp_parity, wordWithLabel.get<parity>());
}

TEST(GetWordTest, DISABLE_ComplexWordWithNegDoubleData)
{
    struct label : elda::arinc429::data_descriptor<label, 1, 8, uint8_t>
    {
    };
    struct data_0 : elda::arinc429::data_descriptor<data_0, 11, 13, uint8_t>
    {
    };
    struct data_1 : elda::arinc429::data_descriptor<data_1, 14, 15, uint8_t>
    {
    };
    struct data_2 : elda::arinc429::data_descriptor<data_2, 18, 29, double, std::ratio<88, 1000>>
    {
    };
    struct state_matrix : elda::arinc429::data_descriptor<state_matrix, 30, 31, uint8_t>
    {
    };
    struct parity : elda::arinc429::data_descriptor<parity, 32, 32, uint8_t>
    {
    };

    using word_with_label_t =
        elda::arinc429::word_generic<label, data_0, data_1, data_2, state_matrix, parity>;

    constexpr uint8_t exp_label = 0162;
    constexpr uint8_t exp_data_0 = 6;
    constexpr uint8_t exp_data_1 = 0;
    constexpr double exp_data_2 = -135.78399999999999;
    constexpr uint8_t exp_state_matrix = 3;
    constexpr uint8_t exp_parity = 1;

    word_with_label_t wordWithLabel{ 0 };

    // 0xf3f21872
    wordWithLabel.set<label>(exp_label);
    wordWithLabel.set<data_0>(exp_data_0);
    wordWithLabel.set<data_1>(exp_data_1);
    wordWithLabel.set<data_2>(exp_data_2);
    wordWithLabel.set<state_matrix>(exp_state_matrix);
    wordWithLabel.set<parity>(exp_parity);
}

TEST(SetAndGetWordTests, Uint32DataWord)
{
    struct label : elda::arinc429::data_descriptor<label, 1, 8, uint8_t>
    {
    };
    struct data : elda::arinc429::data_descriptor<data, 9, 29, uint32_t>
    {
    };
    struct state_matrix : elda::arinc429::data_descriptor<state_matrix, 30, 31, uint8_t>
    {
    };
    struct parity : elda::arinc429::data_descriptor<parity, 32, 32, uint8_t>
    {
    };

    using word_with_label_t = elda::arinc429::word_generic<label, data, state_matrix, parity>;

    constexpr uint8_t exp_label = 0312;
    constexpr uint32_t exp_data = 1048575;
    constexpr uint8_t exp_state_matrix = 3;
    constexpr uint8_t exp_parity = 1;

    word_with_label_t wordWithLabel{ 0 };

    wordWithLabel.set<label>(exp_label);
    wordWithLabel.set<data>(exp_data);
    wordWithLabel.set<state_matrix>(exp_state_matrix);
    wordWithLabel.set<parity>(exp_parity);

    EXPECT_EQ(exp_label, wordWithLabel.get<label>());
    EXPECT_EQ(exp_data, wordWithLabel.get<data>());
    EXPECT_EQ(exp_state_matrix, wordWithLabel.get<state_matrix>());
    EXPECT_EQ(exp_parity, wordWithLabel.get<parity>());
}

TEST(SetAndGetWordTests, Int32DataWord)
{
    struct label : elda::arinc429::data_descriptor<label, 1, 8, uint8_t>
    {
    };
    struct data : elda::arinc429::data_descriptor<data, 9, 29, int32_t>
    {
    };
    struct state_matrix : elda::arinc429::data_descriptor<state_matrix, 30, 31, uint8_t>
    {
    };
    struct parity : elda::arinc429::data_descriptor<parity, 32, 32, uint8_t>
    {
    };

    using word_with_label_t = elda::arinc429::word_generic<label, data, state_matrix, parity>;

    constexpr uint8_t exp_label = 0377;
    constexpr int32_t exp_data = -9;
    constexpr uint8_t exp_state_matrix = 3;
    constexpr uint8_t exp_parity = 1;

    word_with_label_t wordWithLabel{ 0 };

    wordWithLabel.set<label>(exp_label);
    wordWithLabel.set<data>(exp_data);
    wordWithLabel.set<state_matrix>(exp_state_matrix);
    wordWithLabel.set<parity>(exp_parity);

    EXPECT_EQ(exp_label, wordWithLabel.get<label>());
    EXPECT_EQ(exp_data, wordWithLabel.get<data>());
    EXPECT_EQ(exp_state_matrix, wordWithLabel.get<state_matrix>());
    EXPECT_EQ(exp_parity, wordWithLabel.get<parity>());
}

TEST(SetAndGetWordTests, PosDoubleDataWord)
{
    struct label : elda::arinc429::data_descriptor<label, 1, 8, uint8_t>
    {
    };
    struct data : elda::arinc429::data_descriptor<data, 9, 29, double, std::ratio<23, 1000>>
    {
    };
    struct state_matrix : elda::arinc429::data_descriptor<state_matrix, 30, 31, uint8_t>
    {
    };
    struct parity : elda::arinc429::data_descriptor<parity, 32, 32, uint8_t>
    {
    };

    using word_with_label_t = elda::arinc429::word_generic<label, data, state_matrix, parity>;

    constexpr uint8_t exp_label = 0112;
    constexpr double data_scale_factor = 0.023;
    constexpr double exp_data = 524287 * data_scale_factor;
    constexpr uint8_t exp_state_matrix = 3;
    constexpr uint8_t exp_parity = 1;

    word_with_label_t wordWithLabel{ 0 };

    wordWithLabel.set<label>(exp_label);
    wordWithLabel.set<data>(exp_data);
    wordWithLabel.set<state_matrix>(exp_state_matrix);
    wordWithLabel.set<parity>(exp_parity);

    EXPECT_EQ(exp_label, wordWithLabel.get<label>());
    EXPECT_EQ(exp_data, wordWithLabel.get<data>());
    EXPECT_EQ(exp_state_matrix, wordWithLabel.get<state_matrix>());
    EXPECT_EQ(exp_parity, wordWithLabel.get<parity>());
}

TEST(SetAndGetWordTests, NegDoubleDataWord)
{
    struct label : elda::arinc429::data_descriptor<label, 1, 8, uint8_t>
    {
    };
    struct data : elda::arinc429::data_descriptor<data, 9, 29, double, std::ratio<23, 1000>>
    {
    };
    struct state_matrix : elda::arinc429::data_descriptor<state_matrix, 30, 31, uint8_t>
    {
    };
    struct parity : elda::arinc429::data_descriptor<parity, 32, 32, uint8_t>
    {
    };

    using word_with_label_t = elda::arinc429::word_generic<label, data, state_matrix, parity>;

    constexpr uint8_t exp_label = 0112;
    constexpr double data_scale_factor = 0.023;
    constexpr double exp_data = 524287 * data_scale_factor * -1.;
    constexpr uint8_t exp_state_matrix = 3;
    constexpr uint8_t exp_parity = 1;

    word_with_label_t wordWithLabel{ 0 };

    wordWithLabel.set<label>(exp_label);
    wordWithLabel.set<data>(exp_data);
    wordWithLabel.set<state_matrix>(exp_state_matrix);
    wordWithLabel.set<parity>(exp_parity);

    EXPECT_EQ(exp_label, wordWithLabel.get<label>());
    EXPECT_EQ(exp_data, wordWithLabel.get<data>());
    EXPECT_EQ(exp_state_matrix, wordWithLabel.get<state_matrix>());
    EXPECT_EQ(exp_parity, wordWithLabel.get<parity>());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
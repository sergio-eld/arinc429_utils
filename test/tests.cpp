
#include "arinc429/arinc429.h"

#include <gtest/gtest.h>

#include <cmath>

TEST(ElementaryTests, RewriteDataInHead)
{
    struct data : eld::arinc429::data_descriptor<data, 1, 8, uint8_t> {};

    using word_t =
    eld::arinc429::word_generic<data>;

    word_t word{ 0 };
    word.set<data>(255u);

    constexpr uint8_t exp_label = 32;
    word.set<data>(exp_label);

    EXPECT_EQ(exp_label, word.get<data>());
}

TEST(ElementaryTests, RewriteDataInCenter)
{
    struct data : eld::arinc429::data_descriptor<data, 17, 24, uint8_t> {};

    using word_t =
    eld::arinc429::word_generic<data>;

    word_t word{ 0 };
    word.set<data>(255u);

    constexpr uint8_t exp_data = 32;
    word.set<data>(exp_data);

    EXPECT_EQ(exp_data, word.get<data>());
}

TEST(ElementaryTests, RewriteDataInTail)
{
    struct data : eld::arinc429::data_descriptor<data, 25, 32, uint8_t> {};

    using word_t =
    eld::arinc429::word_generic<data>;

    word_t word{ 0 };
    word.set<data>(255u);

    constexpr uint8_t exp_data = 32;
    word.set<data>(exp_data);

    EXPECT_EQ(exp_data, word.get<data>());
}

TEST(ElementaryTests, SingleUint32DataInHead)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 1, 10, uint32_t> {};

    using word_t =
    eld::arinc429::word_generic<data_0>;

    const auto exp_data_0 = uint32_t(std::pow(2, 10) - 1);

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
}

TEST(ElementaryTests, SingleUint32DataInCenter)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 11, 20, uint32_t> {};

    using word_t =
    eld::arinc429::word_generic<data_0>;

    const auto exp_data_0 = uint32_t(std::pow(2, 10) - 1);

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
}

TEST(ElementaryTests, SingleUint32DataInTail)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 21, 32, uint32_t> {};

    using word_t =
    eld::arinc429::word_generic<data_0>;

    const auto exp_data_0 = uint32_t(std::pow(2, 10) - 1);

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
}

TEST(ElementaryTests, SingleInt32DataInHead)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 1, 10, int32_t> {};

    using word_t =
    eld::arinc429::word_generic<data_0>;

    const auto exp_data_0 = - int32_t(std::pow(2, 9) - 1);

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
}

TEST(ElementaryTests, SingleInt32DataInCenter)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 11, 20, int32_t> {};

    using word_t =
    eld::arinc429::word_generic<data_0>;

    const auto exp_data_0 = - int32_t(std::pow(2, 9) - 1);

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
}

TEST(ElementaryTests, SingleInt32DataInTail)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 21, 32, int32_t> {};

    using word_t =
    eld::arinc429::word_generic<data_0>;

    const auto exp_data_0 = - int32_t(std::pow(2, 9) - 1);

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
}

TEST(ElementaryTests, SingleDoubleDataInHead)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 1, 10, double, std::ratio<1, 100>> {};

    using word_t =
    eld::arinc429::word_generic<data_0>;

    const double exp_data_0 = 3.33;

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
}

TEST(ElementaryTests, SingleDoubleDataInCenter)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 11, 20, double, std::ratio<1, 100>> {};

    using word_t =
    eld::arinc429::word_generic<data_0>;

    const double exp_data_0 = 3.33;

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
}

TEST(ElementaryTests, SingleDoubleDataInTail)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 21, 32, double, std::ratio<1, 100>> {};

    using word_t =
    eld::arinc429::word_generic<data_0>;

    const double exp_data_0 = 3.33;

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
}

TEST(ElementaryTests, FullCamapcityDataUint)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 1, 32, uint32_t> {};

    using word_t =
    eld::arinc429::word_generic<data_0>;

    const auto exp_data_0 = uint32_t(std::pow(2, 32) - 1);

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
}

TEST(ElementaryTests, FullCamapcityDataInt)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 1, 32, int32_t> {};

    using word_t =
    eld::arinc429::word_generic<data_0>;

    const auto exp_data_0 = - int32_t(std::pow(2, 31) - 1);

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
}

TEST(ElementaryTests, FullCamapcityDataDouble)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 1, 32, double, std::ratio<3, 100>> {};

    using word_t =
    eld::arinc429::word_generic<data_0>;

    const auto exp_data_0 = -(std::pow(2, 31) - 1) * 0.03;

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
}

TEST(ElementaryTests, MultipleUint32Data)
{
    struct data_0 : eld::arinc429::data_descriptor<data_0, 1, 10, uint32_t> {};
    struct data_1 : eld::arinc429::data_descriptor<data_1, 11, 20, uint32_t> {};
    struct data_2 : eld::arinc429::data_descriptor<data_2, 21, 32, uint32_t> {};

    using word_t =
    eld::arinc429::word_generic<data_0, data_1, data_2>;

    const auto exp_data_0 = uint32_t(std::pow(2, 10) - 1);
    const auto exp_data_1 = 9;
    const auto exp_data_2 = uint32_t(std::pow(2, 12) - 1);

    word_t word{ 0 };

    word.set<data_0>(exp_data_0);
    word.set<data_1>(exp_data_1);
    word.set<data_2>(exp_data_2);

    EXPECT_EQ(exp_data_0, word.get<data_0>());
    EXPECT_EQ(exp_data_1, word.get<data_1>());
    EXPECT_EQ(exp_data_2, word.get<data_2>());
}

TEST(SetWordTest, ComplexWordWithNegDoubleData)
{
    struct label : eld::arinc429::data_descriptor<label, 1, 8, uint8_t>
    {
    };
    struct data_0 : eld::arinc429::data_descriptor<data_0, 11, 13, uint8_t>
    {
    };
    struct data_1 : eld::arinc429::data_descriptor<data_1, 14, 15, uint8_t>
    {
    };
    struct data_2 : eld::arinc429::data_descriptor<data_2, 18, 29, double, std::ratio<88, 1000>>
    {
    };
    struct state_matrix : eld::arinc429::data_descriptor<state_matrix, 30, 31, uint8_t>
    {
    };
    struct parity : eld::arinc429::data_descriptor<parity, 32, 32, uint8_t>
    {
    };

    using word_with_label_t =
        eld::arinc429::word_generic<label, data_0, data_1, data_2, state_matrix, parity>;

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

TEST(GetWordTest, ComplexWordWithNegDoubleData)
{
    struct label : eld::arinc429::data_descriptor<label, 1, 8, uint8_t>
    {
    };
    struct data_0 : eld::arinc429::data_descriptor<data_0, 11, 13, uint8_t>
    {
    };
    struct data_1 : eld::arinc429::data_descriptor<data_1, 14, 15, uint8_t>
    {
    };
    struct data_2 : eld::arinc429::data_descriptor<data_2, 18, 29, double, std::ratio<88, 1000>>
    {
    };
    struct state_matrix : eld::arinc429::data_descriptor<state_matrix, 30, 31, uint8_t>
    {
    };
    struct parity : eld::arinc429::data_descriptor<parity, 32, 32, uint8_t>
    {
    };

    using word_with_label_t =
        eld::arinc429::word_generic<label, data_0, data_1, data_2, state_matrix, parity>;

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

    EXPECT_EQ(0xf3f21872, wordWithLabel.get_raw());
}

TEST(SetAndGetWordTests, Uint32DataWord)
{
    struct label : eld::arinc429::data_descriptor<label, 1, 8, uint8_t>
    {
    };
    struct data : eld::arinc429::data_descriptor<data, 9, 29, uint32_t>
    {
    };
    struct state_matrix : eld::arinc429::data_descriptor<state_matrix, 30, 31, uint8_t>
    {
    };
    struct parity : eld::arinc429::data_descriptor<parity, 32, 32, uint8_t>
    {
    };

    using word_with_label_t = eld::arinc429::word_generic<label, data, state_matrix, parity>;

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
    struct label : eld::arinc429::data_descriptor<label, 1, 8, uint8_t>
    {
    };
    struct data : eld::arinc429::data_descriptor<data, 9, 29, int32_t>
    {
    };
    struct state_matrix : eld::arinc429::data_descriptor<state_matrix, 30, 31, uint8_t>
    {
    };
    struct parity : eld::arinc429::data_descriptor<parity, 32, 32, uint8_t>
    {
    };

    using word_with_label_t = eld::arinc429::word_generic<label, data, state_matrix, parity>;

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
    struct label : eld::arinc429::data_descriptor<label, 1, 8, uint8_t>
    {
    };
    struct data : eld::arinc429::data_descriptor<data, 9, 29, double, std::ratio<23, 1000>>
    {
    };
    struct state_matrix : eld::arinc429::data_descriptor<state_matrix, 30, 31, uint8_t>
    {
    };
    struct parity : eld::arinc429::data_descriptor<parity, 32, 32, uint8_t>
    {
    };

    using word_with_label_t = eld::arinc429::word_generic<label, data, state_matrix, parity>;

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
    struct label : eld::arinc429::data_descriptor<label, 1, 8, uint8_t>
    {
    };
    struct data : eld::arinc429::data_descriptor<data, 9, 29, double, std::ratio<23, 1000>>
    {
    };
    struct state_matrix : eld::arinc429::data_descriptor<state_matrix, 30, 31, uint8_t>
    {
    };
    struct parity : eld::arinc429::data_descriptor<parity, 32, 32, uint8_t>
    {
    };

    using word_with_label_t = eld::arinc429::word_generic<label, data, state_matrix, parity>;

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

TEST(CustomizationTests, CustomizedSetter)
{
    constexpr uint32_t scale_factor = 16;

    struct data : eld::arinc429::data_descriptor<data, 9, 29, uint32_t>
    {
        void operator()(value_type value,
                        eld::arinc429::traits::word_raw_type &raw_word,
                        eld::arinc429::tag_set)
        {
            value_type to_set_value = value / scale_factor;
            eld::arinc429::detail::set_value<data>(to_set_value, raw_word, std::false_type{});
        }
    };

    uint32_t set_value = 32;
    uint32_t expected_value = set_value / scale_factor;

    using word_type = eld::arinc429::word_generic<data>;

    word_type word{ 0 };
    word.set<data>(set_value);

    auto get_value = word.get<data>();

    EXPECT_EQ(get_value, expected_value);
}

TEST(CustomizationTests, CustomizedGetter)
{
    constexpr uint32_t scale_factor = 32;

    struct data : eld::arinc429::data_descriptor<data, 9, 29, uint32_t>
    {
        void operator()(value_type &dest,
                        eld::arinc429::traits::word_raw_type raw_word,
                        eld::arinc429::tag_get)
        {
            eld::arinc429::detail::get_value<data>(dest, raw_word, std::false_type{});
            dest *= scale_factor;
        }
    };

    uint32_t set_value = 20;
    uint32_t expected_value = set_value * scale_factor;

    using word_type = eld::arinc429::word_generic<data>;

    word_type word{ 0 };
    word.set<data>(set_value);

    auto get_value = word.get<data>();

    EXPECT_EQ(get_value, expected_value);
}

TEST(CustomizationTests, CustomizedSetterAndGetter)
{
    constexpr uint32_t scale_factor = 32;

    struct data : eld::arinc429::data_descriptor<data, 9, 29, uint32_t>
    {
        void operator()(value_type value,
                        eld::arinc429::traits::word_raw_type &raw_word,
                        eld::arinc429::tag_set)
        {
            value_type to_set_value = value / scale_factor;
            eld::arinc429::detail::set_value<data>(to_set_value, raw_word, std::false_type{});
        }

        void operator()(value_type &dest,
                        eld::arinc429::traits::word_raw_type raw_word,
                        eld::arinc429::tag_get)
        {
            eld::arinc429::detail::get_value<data>(dest, raw_word, std::false_type{});
            dest *= scale_factor;
        }
    };

    uint32_t set_value = 64;

    using word_type = eld::arinc429::word_generic<data>;

    word_type word{ 0 };
    word.set<data>(set_value);

    auto get_value = word.get<data>();

    EXPECT_EQ(get_value, set_value);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
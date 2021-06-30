
#include "arinc429/arinc429.h"

namespace arinc429 = eld::arinc429;

int main()
{
    constexpr auto sum = std::integral_constant<int, eld::arinc429::detail::sum(4, 8, 15, 16) - 1>();
    static_assert(42 == sum, "");

    struct label {};
    using label_descriptor = eld::arinc429::data_descriptor<label, 1, 8, uint8_t>;

    using word_with_label_t = eld::arinc429::word_generic<label_descriptor>;

    word_with_label_t wordWithLabel{07};

    auto labelValue = wordWithLabel.get<label>();
    (void)labelValue;
    wordWithLabel.set<label>(011);

    static_assert(std::is_same<uint8_t, eld::arinc429::traits::value_type_t<label_descriptor>>(), "");
    static_assert(std::is_same<label_descriptor, eld::arinc429::traits::get_data_descriptor_t<label, word_with_label_t>>(), "");
    static_assert(std::is_same<uint8_t, eld::arinc429::traits::value_type_t<eld::arinc429::traits::get_data_descriptor_t<label, word_with_label_t>>>(), "");


    static_assert(std::is_same<uint8_t, typename eld::arinc429::modifier<label, word_with_label_t>::value_type>(), "");

    eld::arinc429::modify<label>(wordWithLabel) += uint8_t(26);
    auto label_modifier = eld::arinc429::modify<label>(wordWithLabel);

    label_modifier += uint8_t(26);

    struct with_getter_and_setter
    {
        void operator()(const int&, eld::arinc429::traits::word_raw_type&, eld::arinc429::tag_set)
        {}

        void operator()(int&, eld::arinc429::traits::word_raw_type, eld::arinc429::tag_get)
        {}
    };

    static_assert(eld::arinc429::traits::defines_getter<with_getter_and_setter, int>(), "");
    static_assert(eld::arinc429::traits::defines_setter<with_getter_and_setter, int>(), "");

    return 0;
}

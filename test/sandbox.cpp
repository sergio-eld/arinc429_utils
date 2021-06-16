
#include "arinc429/arinc429.h"

int main()
{
    constexpr auto sum = std::integral_constant<int, eld::arinc429::detail::sum(4, 8, 15, 16) - 1>();
    static_assert(42 == sum, "");

    struct label : eld::arinc429::data_descriptor<label, 1, 8, uint8_t>{};

    using word_with_label_t = eld::arinc429::word_generic<label>;

    word_with_label_t wordWithLabel{07};

    auto labelValue = wordWithLabel.get<label>();
    wordWithLabel.set<label>(011);

    return 0;
}

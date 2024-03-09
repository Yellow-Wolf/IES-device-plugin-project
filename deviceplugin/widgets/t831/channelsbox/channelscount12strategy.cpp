#include "channelscount12strategy.h"


void ChannelsCount12Strategy::initUI(std::vector<ChannelButton*> *buttons, QGroupBox *channels_box) {
  channels_count = 12;

  channels_box->setFont(header_group_box_font);
  channels_box->setFixedSize(500, 230);
  channels_box->setTitle("Список каналов");

  auto main_layout = new QGridLayout(channels_box);

  for (int i = 0; i < 3; ++i) {
    auto group_name = new QLabel(QString("%1").arg(char('A' + i)), channels_box);
    main_layout->addWidget(group_name, i, 0);
    group_name->setFont(fonts.channl_box_name);

    for (int j = 0; j < 4; ++j) {
      auto *current_button = new ChannelButton(("Канал " + std::to_string(j + 1)).c_str(), channels_box);
      buttons->push_back(current_button);
      main_layout->addWidget((*buttons)[i*4 + j], i, j + 1);
    }
  }
}

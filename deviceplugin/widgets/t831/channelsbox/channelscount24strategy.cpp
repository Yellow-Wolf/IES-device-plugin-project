#include "channelscount24strategy.h"


void ChannelsCount24Strategy::initUI(std::vector<ChannelButton*> *buttons, QGroupBox *channels_box) {
  channels_count = 24;

  channels_box->setFont(header_group_box_font);
  channels_box->setFixedSize(550, 500);
  channels_box->setTitle("Список каналов");

  auto *main_layout = new QGridLayout(channels_box);

  for (int i = 0; i < 3; ++i) {
    auto *group_box = new QGroupBox(channels_box);
    main_layout->addWidget(group_box, i, 0);
    group_box->setFixedSize(500, 150);
    auto *group_box_layout = new QGridLayout(group_box);

    auto group_name = new QLabel(QString("%1").arg(char('A' + i)), channels_box);
    group_box_layout->addWidget(group_name, 0, 0, 2, 1);
    group_name->setFont(fonts.channl_box_name);

    for (int j = 0; j < 8; ++j){
      auto *current_button = new ChannelButton(("Канал " + std::to_string(j + 1)).c_str(), channels_box);
      buttons->push_back(current_button);
      group_box_layout->addWidget((*buttons)[i*8 + j], j/4, j%4 + 1);
    }
  }
}

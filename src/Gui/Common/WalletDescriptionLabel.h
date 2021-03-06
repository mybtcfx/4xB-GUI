/*
 * Copyright (c) 2017-2018, The 4xbitcoin Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of 4xbitcoin.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#pragma once

#include <QLabel>

namespace WalletGui {

class WalletDescriptionLabel : public QLabel {
  Q_OBJECT
  Q_DISABLE_COPY(WalletDescriptionLabel)

public:
  explicit WalletDescriptionLabel(QWidget* _parent);
  ~WalletDescriptionLabel();
};

}

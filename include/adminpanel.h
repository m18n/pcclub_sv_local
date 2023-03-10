#pragma once
#include "crow.h"

class AdminPanel {
 private:
  void initcrow();

 public:
  AdminPanel();
  AdminPanel(int port);
  void setport(int port);
  void startcrow();
  void startcrow(int port);
  void stopcrow();
 private:
  crow::SimpleApp adminpanel;
  int port;
  bool workcrow;
};
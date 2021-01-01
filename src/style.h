#pragma once

// Sets the style for Nuklear
static void set_style(struct nk_context* ctx) {
  struct nk_color table[NK_COLOR_COUNT];

  table[NK_COLOR_TEXT]           = nk_rgba(174,  76,  14, 255);
  table[NK_COLOR_WINDOW]         = nk_rgba(208, 195, 161, 255);
  table[NK_COLOR_HEADER]         = nk_rgba(213, 163,  94, 255);

  table[NK_COLOR_BORDER] = nk_rgba(50, 50, 50, 255);
  table[NK_COLOR_BUTTON] = nk_rgba(185, 185, 185, 255);
  table[NK_COLOR_BUTTON_HOVER] = nk_rgba(170, 170, 170, 255);
  table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(160, 160, 160, 255);
  table[NK_COLOR_TOGGLE] = nk_rgba(150, 150, 150, 255);
  table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(120, 120, 120, 255);
  table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(175, 175, 175, 255);
  table[NK_COLOR_SELECT] = nk_rgba(190, 190, 190, 255);
  table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(175, 175, 175, 255);
  table[NK_COLOR_SLIDER] = nk_rgba(190, 190, 190, 255);
  table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(80, 80, 80, 255);
  table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(70, 70, 70, 255);
  table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(60, 60, 60, 255);
  table[NK_COLOR_PROPERTY] = nk_rgba(175, 175, 175, 255);
  table[NK_COLOR_EDIT] = nk_rgba(150, 150, 150, 255);
  table[NK_COLOR_EDIT_CURSOR] = nk_rgba(0, 0, 0, 255);
  table[NK_COLOR_COMBO] = nk_rgba(175, 175, 175, 255);
  table[NK_COLOR_CHART] = nk_rgba(160, 160, 160, 255);
  table[NK_COLOR_CHART_COLOR] = nk_rgba(45, 45, 45, 255);
  table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba( 255, 0, 0, 255);
  table[NK_COLOR_SCROLLBAR] = nk_rgba(180, 180, 180, 255);
  table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(140, 140, 140, 255);
  table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(150, 150, 150, 255);
  table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(160, 160, 160, 255);
  table[NK_COLOR_TAB_HEADER] = nk_rgba(180, 180, 180, 255);

  nk_style_from_table(ctx, table);
}

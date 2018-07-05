#ifndef STYLE_H
#define STYLE_H

#define WIN_POSX        500
#define WIN_POSY        200

#define WIN_X           1400
#define WIN_Y           900

#define HELP_WIN_X      1000
#define HELP_WIN_Y      700

#define MARGIN_X        50
#define MARGIN_Y        50

#define BTN_WIDTH       175
#define BTN_HEIGHT      50
#define BTN_SPACE       (BTN_HEIGHT + 20)
#define BTN_DRAW_POSX   (MARGIN_X + GRAPH_WIDTH - 150)
#define BTN_DRAW_POSY   (GRAPH_POSY + GRAPH_HEIGHT + GRAPH_SPACE)
#define BTN_NEW_POSX    BTN_DRAW_POSX
#define BTN_NEW_POSY    BTN_DRAW_POSY + BTN_SPACE
#define BTN_REM_POSX    BTN_DRAW_POSX
#define BTN_REM_POSY    BTN_NEW_POSY + BTN_SPACE
#define BTN_HELP_POSX   BTN_DRAW_POSX
#define BTN_HELP_POSY   BTN_REM_POSY + BTN_SPACE

#define LBL_WIDTH       500
#define LBL_HEIGHT      40
#define LBL_SPACE       (FONT_SIZE + 40)
#define LBL_NBRP_POSX   TABLE_POSX
#define LBL_NBRP_POSY   (TABLE_HEIGHT + TABLE_POSY + TABLE_SPACE)

#define EDIT_WIDTH      625
#define EDIT_HEIGHT     40
#define EDIT_SPACE      (EDIT_HEIGHT + 20)
#define EDIT_CMD_POSX   MARGIN_X
#define EDIT_CMD_POSY   (GRAPH_POSY + GRAPH_HEIGHT + GRAPH_SPACE)
#define EDIT_FUNC_POSX  MARGIN_X
#define EDIT_FUNC_POSY  (EDIT_CMD_POSY + EDIT_SPACE)

#define LIST_WIDTH      EDIT_WIDTH
#define LIST_HEIGHT     EDIT_HEIGHT
#define LIST_SPACE      EDIT_SPACE
#define LIST_FUNC_POSX  MARGIN_X
#define LIST_FUNC_POSY  (EDIT_FUNC_POSY + EDIT_SPACE)

#define DFLT_NBR_ROW    20
#define DFLT_NBR_COLUMN 2
#define TABLE_CELLX     200
#define TABLE_CELLY     40
#define TABLE_ID        40
#define TABLE_SCROLL    10
#define TABLE_SPACE     10
#define TABLE_MARGIN_X  MARGIN_X
#define TABLE_MARGIN_Y  MARGIN_Y //WIN_Y - (2 * TABLE_CELLY)//2 * TABLE_CELLY
#define TABLE_WIDTH     (DFLT_NBR_COLUMN * TABLE_CELLX + TABLE_ID + TABLE_SCROLL)
#define TABLE_HEIGHT    (WIN_Y - 2 * MARGIN_X)
#define TABLE_POSX      (WIN_X - TABLE_WIDTH - MARGIN_X)
#define TABLE_POSY      MARGIN_Y

#define GRAPH_WIDTH     800
#define GRAPH_HEIGHT    500
#define GRAPH_SPACE     40
#define GRAPH_POSX      MARGIN_X
#define GRAPH_POSY      MARGIN_Y

#define FONT_TYPE       "Arial"
#define FONT_SIZE       8
#define FONT_COLOR      QColor(150, 150, 150)

#define BACKGROUND  QColor(60, 60, 60)

#endif // STYLE_H

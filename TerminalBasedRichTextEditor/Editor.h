﻿#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include "Cursor.h"
#include "DebugUtils.h"
#include "GapBufferLinkedList.h"
#include "StatusBar.h"
#include "Utils.h"
#include <conio.h>
#include <experimental/filesystem>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

enum Action {
	INSERT,
	DELETE,
	MOVE_CURSOR,
};

class Editor {
private:

    pair<int, int> local_current_pos;
    pair<int, int> absolute_screen_size;
    int left_bound;
    int right_bound;
    int top_bound;
    int bottom_bound;

    int left_gap;
    bool is_file_saved;
    string file_path;

    string file_name;
    GapBufferLinkedList gapBufferEditor;
    StatusBar statusBar;

    Action handleKeyInput(int key);
    void render();
    void renderLineNumber(int row);
    void renderAllLinesFromCursor();

    pair<int, int> getAbsPos(const pair<int, int>& pos) const;
    int getAbsRow(int row) const;
    int getAbsCol(int col) const;

public:
    Editor();
    void run();
};
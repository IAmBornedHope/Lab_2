#pragma once
#include <wx/wx.h>
#include <wx/listbox.h>
#include <wx/combobox.h>
#include <wx/statline.h>
#include <wx/notebook.h>
#include <wx/grid.h>
#include <wx/spinctrl.h>
#include <string>
#include <format>
#include "../sequence/Sequence.hpp"
#include "../array_sequence/ArraySequence.hpp"
#include "../array_sequence/MutableArraySequence.hpp"
#include "../exceptions/Exceptions.hpp"
#include "../hanoi/HanoiTower.hpp"
#include "../stack/Stack.hpp"
#include "../square_matrix/SquareMatrix.hpp"
#include "../my_types/Complex.hpp"

using MyComplex = Complex<double>;
using Matrix = SquareMatrix<Complex<double>, MutableArraySequence>;

class MyFrame : public wxFrame {
public:
    MyFrame();
    ~MyFrame();

private:
    // ВКЛАДКА STACK
    void on_create_stack(wxCommandEvent& event);
    void on_select_object(wxCommandEvent& event);
    void on_select_target(wxCommandEvent& event);
    void on_push(wxCommandEvent& event);
    void on_pop(wxCommandEvent& event);
    void on_get_length(wxCommandEvent& event);
    void on_substack(wxCommandEvent& event);
    void on_concat(wxCommandEvent& event);
    void on_clear(wxCommandEvent& event);

    void update_comboboxes();
    void show_stack();
    void update_current_length();
    void update_concat();
    void update_operations(const Stack<double, MutableArraySequence>& stack);
    void add_stack_to_list(const Stack<double, MutableArraySequence>& new_stack);
    bool get_input(wxTextCtrl* ctrl, double& value);

    Stack<double, MutableArraySequence>& get_active_stack();
    Stack<double, MutableArraySequence>& get_target_stack();
    
    size_t current_stack_id = 0;
    size_t max_elem_length = 4;
    MutableArraySequence<Stack<double, MutableArraySequence>> stacks;
    
    wxComboBox* object_selector;
    wxComboBox* target_selector;
    
    wxButton* button_clear;
    wxButton* button_pop;
    wxButton* button_substack;
    wxButton* button_concat;

    wxTextCtrl* input_value;
    wxTextCtrl* input_index;
    
    wxListBox* stack_list_box;

    wxStaticText* current_length;

    // ВКЛАДКА HANOI
    void on_hanoi_init(wxCommandEvent& event);
    void on_next_move(wxCommandEvent& event);
    void on_prev_move(wxCommandEvent& event);
    void on_hanoi_reset(wxCommandEvent& event);
    void on_hanoi_auto_mode(wxCommandEvent& event);
    void on_hanoi_stop(wxCommandEvent& event);
    void update_hanoi_buttons();
    void show_hanoi();
    void hanoi_next();

    std::string draw_ring(const Ring& ring);

    HanoiTower<Ring> tower;
    MutableArraySequence<HanoiMove> moves;
    size_t current_move_id = 0;
    bool is_auto = false;

    wxSpinCtrl* ring_counter;
    wxComboBox* start_selector;

    wxTextCtrl* first_rod_visual;
    wxTextCtrl* second_rod_visual;
    wxTextCtrl* third_rod_visual;

    wxStaticText* game_status;

    wxButton* button_auto;
    wxButton* button_stop;
    wxButton* button_prev;
    wxButton* button_next;

    // ВКЛАДКА МАТРИЦ

    void on_create_matrix(wxCommandEvent& event);
    void on_select_first_matrix(wxCommandEvent& event);
    void on_select_second_matrix(wxCommandEvent& event);
    void on_matrix_add(wxCommandEvent& event);
    void on_matrix_multiply(wxCommandEvent& event);
    void on_matrix_scalar(wxCommandEvent& event);
    void on_matrix_inverse(wxCommandEvent& event);

    void on_first_grid_changed(wxGridEvent& event);
    void on_second_grid_changed(wxGridEvent& event);
    void save_first_frid();
    void save_second_grid();

    size_t current_first_id = 0;
    size_t current_second_id = 0;

    MutableArraySequence<Matrix> matrices;

    wxSpinCtrl* matrix_size_ctrl;

    wxComboBox* first_matrix_selector;
    wxComboBox* second_matrix_selector;

    wxGrid* first_grid;
    wxGrid* second_grid;
    wxGrid* result_grid;

    wxTextCtrl* input_scalar;

    wxButton* button_new_matrix;
    wxButton* button_add;
    wxButton* button_multiply;
    wxButton* button_scalar;
    wxButton* button_inverse;

};

int run_gui();

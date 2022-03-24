#ifndef slic3r_GLGizmoFdmSupports_hpp_
#define slic3r_GLGizmoFdmSupports_hpp_

#include "GLGizmoPainterBase.hpp"

namespace Slic3r::GUI {

class GLGizmoFdmSupports : public GLGizmoPainterBase
{
public:
    GLGizmoFdmSupports(GLCanvas3D& parent, const std::string& icon_filename, unsigned int sprite_id)
        : GLGizmoPainterBase(parent, icon_filename, sprite_id) {}

    void render_painter_gizmo() override;

protected:
    void on_render_input_window(float x, float y, float bottom_limit) override;
    std::string on_get_name() const override;

    wxString handle_snapshot_action_name(bool shift_down, Button button_down) const override;

    std::string get_gizmo_entering_text() const override { return _u8L("Entering Paint-on supports"); }
    std::string get_gizmo_leaving_text() const override { return _u8L("Leaving Paint-on supports"); }
    std::string get_action_snapshot_name() override { return _u8L("Paint-on supports editing"); }


private:
    bool on_init() override;

    void update_model_object() const override;
    void update_from_model_object() override;

    void on_opening() override {}
    void on_shutdown() override;
    PainterGizmoType get_painter_type() const override;

    void select_facets_by_angle(float threshold, bool block);

    void compute_smart_support_placement(float limit_angle_deg, float patch_size, float patch_spacing, float islands_tolerance);

    // This map holds all translated description texts, so they can be easily referenced during layout calculations
    // etc. When language changes, GUI is recreated and this class constructed again, so the change takes effect.
    std::map<std::string, wxString> m_desc;

    float m_smart_support_limit_angle_deg = 45.0f;
    float m_smart_support_patch_size = 10.0f; //0.1mm
    float m_smart_support_patch_spacing = 20.0f; //0.1mm
    float m_smart_support_islands_tolerance = 30.0f; //0.01mm
};



} // namespace Slic3r::GUI


#endif // slic3r_GLGizmoFdmSupports_hpp_

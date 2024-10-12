// This file is part of the Godot Orchestrator project.
//
// Copyright (c) 2023-present Crater Crash Studios LLC and its contributors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//		http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef ORCHESTRATOR_SCRIPT_CUSTOM_EVENTS_COMPONENT_PANEL_H
#define ORCHESTRATOR_SCRIPT_CUSTOM_EVENTS_COMPONENT_PANEL_H

#include "editor/component_panels/component_panel.h"

class OrchestratorScriptCustomEventsComponentPanel : public OrchestratorScriptComponentPanel
{
    GDCLASS(OrchestratorScriptCustomEventsComponentPanel, OrchestratorScriptComponentPanel);
    static void _bind_methods();

    enum ContextMenuIds
    {
        CM_RENAME_EVENT,
        CM_REMOVE_EVENT
    };

protected:
    //~ Begin OrchestratorScriptViewSection Interface
    String _get_unique_name_prefix() const override { return "NewEvent"; }
    PackedStringArray _get_existing_names() const override;
    String _get_tooltip_text() const override;
    String _get_remove_confirm_text(TreeItem* p_item) const override;
    String _get_item_name() const override { return "Signal"; }
    bool _populate_context_menu(TreeItem* p_item) override;
    void _handle_context_menu(int p_id) override;
    bool _handle_add_new_item(const String& p_name) override;
    void _handle_item_selected() override;
    void _handle_item_activated(TreeItem* p_item) override;
    bool _handle_item_renamed(const String& p_old_name, const String& p_new_name) override;
    void _handle_remove(TreeItem* p_item) override;
    Dictionary _handle_drag_data(const Vector2& p_position) override;
    void _handle_tree_gui_input(const Ref<InputEvent>& p_event, TreeItem* p_item) override;
    //~ End OrchestratorScriptViewSection Interface

    /// Default constructor
    OrchestratorScriptCustomEventsComponentPanel() = default;

public:
    //~ Begin OrchestratorScriptViewSection Interface
    void update() override;
    //~ End OrchestratorScriptViewSection Interface

    /// Construct a signals component panel
    /// @param p_orchestration the orchestration
    explicit OrchestratorScriptCustomEventsComponentPanel(Orchestration* p_orchestration);
};

#endif // ORCHESTRATOR_SCRIPT_CUSTOM_EVENTS_COMPONENT_PANEL_H

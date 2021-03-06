/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "Engine/Raylib.hpp"

#include <vector>

namespace raylib {
    class Mesh {
    private:
        ::Mesh m_raylibMesh;
    public:
        explicit Mesh(::Mesh raylibMesh);
        ~Mesh();

        static std::vector<Mesh> loadMeshes(const char *filename);

        inline void exportMesh(const char *filename)
        {
            ExportMesh(m_raylibMesh, filename);
        }

        [[nodiscard]] inline const ::Mesh &getRaylibMesh() const noexcept
        {
            return m_raylibMesh;
        }
    };
}

#ifndef __EllipticProblem_H
#define __EllipticProblem_H

#include <string>

namespace METODI_FEM_2D
{
  class EllipticProblem_ProgramConfiguration final
  {
    public:
      double GeometricTolerance() const { return 1.0e-12; }
      std::string ExportFolder() const { return "./Run"; }
      double MeshMaximumTriangleArea() const { return 0.1; }
  };

  class EllipticProblem final
  {
    private:
      const EllipticProblem_ProgramConfiguration& config;

    public:
      EllipticProblem(const EllipticProblem_ProgramConfiguration& config);
      ~EllipticProblem();

      void Run();
  };

}

#endif

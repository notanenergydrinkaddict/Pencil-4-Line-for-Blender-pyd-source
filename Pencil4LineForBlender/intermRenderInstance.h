#pragma once
#include <vector>
#include "pybind11/pybind11.h"
namespace py = pybind11;

namespace interm
{
	class RenderInstance final
	{
	public:
		RenderInstance(py::object srcObject,
			const std::vector<std::vector<float>>& m,
			py::object mesh) :
			_srcObject(srcObject),
			_matrixWorld {
				m[0][0], m[1][0], m[2][0], m[3][0],
				m[0][1], m[1][1], m[2][1], m[3][1],
				m[0][2], m[1][2], m[2][2], m[3][2],
				m[0][3], m[1][3], m[2][3], m[3][3],
			},
			_mesh(mesh)
		{}
		~RenderInstance() {}

		py::object SrcObject() const { return _srcObject; }
		py::object Mesh() const { return _mesh; }

		const float* GetMatrixWorld() const { return _matrixWorld; }

	private:
		py::object _srcObject;
		const float _matrixWorld[16];
		py::object _mesh;
	};

}

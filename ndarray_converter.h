# ifndef __NDARRAY_CONVERTER_H__
# define __NDARRAY_CONVERTER_H__

#include <Python.h>
#include <opencv2/core/core.hpp>


class NDArrayConverter {
public:
    // must call this first, or the other routines don't work!
    static bool init_numpy();

    static bool toMat(PyObject *o, cv::Mat &m);

    static PyObject *toNDArray(const cv::Mat &mat);
};

//
// Define the type converter
//

#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace pybind11 {
    namespace detail {

        template<>
        struct type_caster<cv::Mat> {
        public:

        PYBIND11_TYPE_CASTER(cv::Mat, _("numpy.ndarray"));

            bool load(handle src, bool /* convert */) {
                return NDArrayConverter::toMat(src.ptr(), value);
            }

            static handle cast(const cv::Mat &m, return_value_policy, handle defval) {
                return handle(NDArrayConverter::toNDArray(m));
            }
        };

        //! 实现 cv::Point 和 list(x,y) 之间的转换。
        template<>
        struct type_caster<cv::Point> {

            //! 定义 cv::Point 类型名为 list_xy, 并声明类型为 cv::Point 的局部变量 value。
        PYBIND11_TYPE_CASTER(cv::Point, _("list_xy"));

            //! 步骤1：从 Python 转换到 C++。
            //! 将 Python list 对象转换为 C++ cv::Point 类型, 转换失败则返回 false。
            //! 其中参数2表示是否隐式类型转换。
            bool load(handle obj, bool) {
                // 确保传参是 tuple 类型
                if (!py::isinstance<py::list>(obj)) {
                    std::logic_error("Point(x,y) should be a list!");
                    return false;
                }

                // 从 handle 提取 tuple 对象，确保其长度是2。
                py::tuple pt = reinterpret_borrow<py::list>(obj);
                if (pt.size() != 2) {
                    std::logic_error("Point(x,y) tuple should be size of 2");
                    return false;
                }

                //! 将长度为2的 tuple 转换为 cv::Point。
                value = cv::Point(pt[0].cast<int>(), pt[1].cast<int>());
                return true;
            }

            //! 步骤2： 从 C++ 转换到 Python。
            //! 将 C++ cv::Mat 对象转换到 tuple，参数2和参数3常忽略。
            static handle cast(const cv::Point &pt, return_value_policy, handle) {
                py::list res;
                res.append(pt.x);
                res.append(pt.y);
                py::list out;
                out.append(res);
                return out.release();
            }
        };

    }
} // namespace pybind11::detail

# endif
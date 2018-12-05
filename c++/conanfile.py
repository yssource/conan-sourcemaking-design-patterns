from conans import ConanFile, CMake, tools


class SourcemakingConan(ConanFile):
    name = "sourcemaking"
    version = "0.0.0"
    license = "MIT"
    author = "Jimmy M. Gong yssource@163.com"
    url = "https://github.com/yssource/sourcemaking-design-patterns"
    description = "conan hello gtest example"
    topics = ("conan", "hello", "gtest")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "SIMPLE": [True, False]}
    default_options = {"shared": False, "SIMPLE": True, "boost_test:shared": False}
    generators = "cmake"

#     def source(self):
#         self.run("git clone https://github.com/memsharded/hello.git")
#         self.run("cd hello && git checkout static_shared")
#         # This small hack might be useful to guarantee proper /MT /MD linkage
#         # in MSVC if the packaged project doesn't have variables to set it
#         # properly
#         tools.replace_in_file("hello/CMakeLists.txt", "PROJECT(MyHello)",
#                               '''PROJECT(MyHello)
# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()''')

    def requirements(self):
        # self.requires("boost/1.68.0@{}/{}".format("conan", "stable"))
        self.requires("gtest/1.8.0@{}/{}".format("bincrafters", "stable"))
        self.requires("boost_base/1.67.0@{}/{}".format("bincrafters", "stable"))
        self.requires("boost_format/1.67.0@{}/{}".format("bincrafters", "stable"))

    def build(self):
        cmake = CMake(self)
        # cmake.configure(source_folder="src")
        cmake.configure()
        # cmake.build()
        cmake.install()
        cmake.test()

    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
        # self.env_info.PATH.append(os.path.join(self.package_folder, "bin"))
        # if self.options.shared:
        #     self.env_info.LD_LIBRARY_PATH.append(os.path.join(self.package_folder, "lib"))
        #     self.env_info.DYLD_LIBRARY_PATH.append(os.path.join(self.package_folder, "lib"))

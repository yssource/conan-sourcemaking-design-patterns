from conans import ConanFile, CMake, tools


class SourcemakingConan(ConanFile):
    name = "sourcemaking"
    version = "0.0.0"
    license = "MIT"
    author = "Jimmy M. Gong yssource@163.com"
    url = "https://github.com/yssource/conan-sourcemaking-design-patterns"
    description = "conan-sourcemaking-design-patterns"
    topics = ("conan", "sourcemaking", "design patterns")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "SIMPLE": [True, False]}
    default_options = {"shared": False, "SIMPLE": True, "boost_test:shared": False}
    generators = "cmake"

    def requirements(self):
        self.requires("gtest/1.8.0@{}/{}".format("bincrafters", "stable"))
        self.requires("boost_base/1.67.0@{}/{}".format("bincrafters", "stable"))
        self.requires("boost_format/1.67.0@{}/{}".format("bincrafters", "stable"))

    def build(self):
        cmake = CMake(self)
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

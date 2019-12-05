require "mkmf"
require "rbconfig"

if RbConfig::CONFIG['host_os'] =~ /mingw/
  $CFLAGS << ' -fno-omit-frame-pointer'
end

libdir = RbConfig::CONFIG["libdir"]
includedir = RbConfig::CONFIG["includedir"]

dir_config("ioext", includedir, libdir)

# $LDFLAGS << " "
$CFLAGS << " -Wall -std=c99 -fPIC -fms-extensions "
# $CFLAGS << " -g -O0"

create_makefile("ioext/ioext")

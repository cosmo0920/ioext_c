require_relative "./helper"

class IOExtTest < ::Test::Unit::TestCase
  def setup
    @ioext = IOExt.new
    @default_stdio = @ioext.maxstdio
  end

  def teardown
    @ioext.maxstdio = @default_stdio
  end

  def test_default_maxstdio
    assert_equal(512, @ioext.maxstdio)
  end

  def test_setmaxstdio
    fd = 768
    @ioext.setmaxstdio(fd)
    assert_equal(fd, @ioext.maxstdio)
  end

  def test_setmaxstdio_maximum
    fd = 4096
    limitfd = 2048
    @ioext.setmaxstdio(fd)
    assert_equal(limitfd, @ioext.maxstdio)
  end

  def test_setmaxstdio_minimum
    fd = 20
    @ioext.setmaxstdio(fd)

    assert_equal(IOExt::IOB_ENTRIES, @ioext.maxstdio)
  end

  def test_setmaxstdio_error_setmaxfd
    fd = 10
    assert_equal(-1, @ioext.setmaxstdio(fd))
    assert_equal(@default_stdio, @ioext.maxstdio)
  end
end

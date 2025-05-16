# Copyright 2020- Hiroshi Hatake

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

#     http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

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
    fd = -20
    assert_equal(-1, @ioext.setmaxstdio(fd))
    assert_equal(@default_stdio, @ioext.maxstdio)
  end
end

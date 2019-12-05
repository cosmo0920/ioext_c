begin
  require "ioext/#{RUBY_VERSION[/\d+.\d+/]}/ioext"
rescue LoadError
  require "ioext/ioext"
end
require "ioext/version"

class IOExt
  class Error < StandardError; end
  # Your code goes here...
end

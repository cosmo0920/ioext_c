# IOExt

[![Build status](https://ci.appveyor.com/api/projects/status/iluieyjg62opf7xo/branch/master?svg=true)](https://ci.appveyor.com/project/cosmo0920/ioext-c/branch/master)

IO extenstion with Windows CRT function.
Currently, it is only used for _setmaxstdio/_getmaxstdio functions in Windows C runtime.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'ioext_c'
```

And then execute:

    $ ridk exec bundle

Or install it yourself as:

    $ ridk exec gem install ioext_c

## Development

After checking out the repo, run `bin/setup` to install dependencies. You can also run `bin/console` for an interactive prompt that will allow you to experiment.

To install this gem onto your local machine, run `bundle exec rake install`. To release a new version, update the version number in `version.rb`, and then run `bundle exec rake release`, which will create a git tag for the version, push git commits and tags, and push the `.gem` file to [rubygems.org](https://rubygems.org).

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/cosmo0920/ioext_c.

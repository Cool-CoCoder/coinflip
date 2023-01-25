# Documentation: https://docs.brew.sh/Formula-Cookbook
#                https://rubydoc.brew.sh/Formula
# PLEASE REMOVE ALL GENERATED COMMENTS BEFORE SUBMITTING YOUR PULL REQUEST!
class Coinflip < Formula
  desc ""
  homepage ""
  url "https://github.com/Cool-CoCoder/homebrew-coinflip/blob/master/coinflip_0.tar.gz"
  sha256 "f82f6dee96e3f936141f17c5bf48ab25a102eac437f9b62839385c0d4a25c98d"
  license ""

  # depends_on "cmake" => :build

  def install
    bin.install "coinflip"
  end

  test do
    # `test do` will create, run in and delete a temporary directory.
    #
    # This test will fail and we won't accept that! For Homebrew/homebrew-core
    # this will need to be a test that verifies the functionality of the
    # software. Run the test with `brew test coinflip`. Options passed
    # to `brew install` such as `--HEAD` also need to be provided to `brew test`.
    #
    # The installed folder is not in the path, so use the entire path to any
    # executables being tested: `system "#{bin}/program", "do", "something"`.
    system "false"
  end
end

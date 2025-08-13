import monocle.Lens
import monocle.macros.GenLens

trait Foo[T]
trait Bar[T]

case class A[T: Foo](s: A.S[T]) {
  private val lens: Lens[A.S[T], Bar[T]] = GenLens[A.S[T]](a => a.bar)
}

object A {
  case class S[T: Foo](bar: Bar[T])
}
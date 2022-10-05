let lower = <div />;
let upper = <Input />;
let lower_with_empty_attr = <div className="" />;
let lower_opt_attr = <div ?tabIndex />;
let lower_inner_html = <div dangerouslySetInnerHTML={"__html": text} />;
let lower_with_style =
  <div style={ReactDOM.Style.make(~backgroundColor="gainsboro", ())} />;
let fragment = foo => [@bla] <> foo </>;
let polyChildrenFragment = (foo, bar) => <> foo bar </>;
let nestedFragment = (foo, bar, baz) => <> foo <> bar baz </> </>;
let nestedFragmentWithlower = foo => <> <div> foo </div> </>;
let upper = <Upper />;
let upperWithProp = <Upper count />;
let upperWithChild = foo => <Upper> foo </Upper>;
let upperWithChildren = (foo, bar) => <Upper> foo bar </Upper>;
let lowerWithChildAndProps = foo =>
  <a tabIndex=1 href="https://example.com"> foo </a>;
let lowerWithChildren = (foo, bar) => <lower> foo bar </lower>;
let nestedElement = <Foo.Bar a=1 b="1" />;
let t = <FancyButton ref=buttonRef> <div /> </FancyButton>;
let t = <button ref className="FancyButton"> children </button>;
let lowerWithChildrenComplex =
  <div className="flex-container">
    <div className="sidebar">
      <h2 className="title"> {"jsoo-react" |> s} </h2>
      <nav className="menu">
        <ul>
          {examples
           |> List.map(e => {
                <li key={e.path}>
                  <a
                    href={e.path}
                    onClick={event => {
                      ReactEvent.Mouse.preventDefault(event);
                      ReactRouter.push(e.path);
                    }}>
                    {e.title |> s}
                  </a>
                </li>
              })
           |> React.list}
        </ul>
      </nav>
    </div>
  </div>;

// Components

[@react.component]
let make = (~name="") => {
  <>
    <div> {React.string("First " ++ name)} </div>
    <Hello one="1"> {React.string("2nd " ++ name)} </Hello>
  </>;
};

[@react.component]
let make = (~name="") => {
  <>
    <div> {React.string("First " ++ name)} </div>
    <Hello one="1"> {React.string("2nd " ++ name)} </Hello>
  </>;
};

module Module_component_with_props = {
  [@react.component]
  let make = (~lola, ~cosis) => {
    Js.log(cosis);

    <div> {React.string(lola)} </div>;
  };
};

let upper_create_element = <Module_component_with_props lola="flores" />;

module Memo = {
  [@react.component]
  let make =
    React.memo((~a) => {
      <div> {Printf.sprintf("`a` is %s", a) |> React.string} </div>
    });
};

module MemoCustomCompareProps = {
  [@react.component]
  let make = (~value: string) => {
    <div> <span> {value |> React.string} </span> </div>;
  };

  let make =
    React.memoCustomCompareProps(make, (next, current) =>
      next##value == current##value
    );
};

[@react.component]
let make =
  React.forwardRef((~children, ~buttonRef) => {
    <button ref=buttonRef className="FancyButton"> children </button>
  });

let testAttributes =
  <div translate="yes">
    <picture id="idpicture">
      <img src="picture/img.png" alt="test picture/img.png" id="idimg" />
      <source type_="image/webp" src="picture/img1.webp" />
      <source type_="image/jpeg" src="picture/img2.jpg" />
    </picture>
  </div>;

let randomElement = <text dx="1 2" dy="3 4" />;

[@react.component]
let make = (~name, ~isDisabled=?) => {
  let onClick = event => Js.log(event);
  <button name onClick disabled=isDisabled />;
};

/* It shoudn't remove this :/ */
let () = Module.fn();
let l = 33;

module External = {
  [@react.component] [@otherAttribute "bla"]
  external component: (~a: int, ~b: string) => React.element =
    {|require("my-react-library").MyReactComponent|};
};

module type X_int = {let x: int;};

module Functor = (M: X_int) => {
  let x = M.x + 1;
  [@react.component]
  let make = (~a, ~b, _) => {
    print_endline("This function should be named `Test$Func`", M.x);
    <div />;
  };
};

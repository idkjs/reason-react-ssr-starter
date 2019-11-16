let styles = ReactDOMRe.Style.make(~marginRight="10px", ());
let str = React.string;
[@react.component]
let make = () => {
  <div className="header">
    <Link href="/">
      <a style=styles> {str("Home")} </a>
    </Link>
    <Link href="/about">
      <a style=styles> {str("About")} </a>
    </Link>
    <h1> {str("ReasonReact SSR Starter")} </h1>
  </div>;
};